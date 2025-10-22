#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// ======= Wi-Fi / MQTT / FIWARE =======
#define WIFI_SSID  "Wokwi-GUEST"
#define WIFI_PASS  ""

#define MQTT_HOST  "9.234.138.146"
#define MQTT_PORT  1883
#define APIKEY     "key_vinheria"
#define DEVICE_ID  "lamp007" 

// ======= Pinos =======
#define PIN_DHT   15
#define PIN_LDR   34
#define PIN_TRIG  5
#define PIN_ECHO  18
#define PIN_LED   2

// ======= DHT (Adafruit) =======
#define DHTTYPE   DHT22
DHT dht(PIN_DHT, DHTTYPE);

// ======= MQTT =======
WiFiClient espClient;
PubSubClient mqtt(espClient);

String topicAttrs() { return "/ul/" + String(APIKEY) + "/" + String(DEVICE_ID) + "/attrs"; }
String topicCmd()   { return "/ul/" + String(APIKEY) + "/" + String(DEVICE_ID) + "/cmd"; }

long lastSend = 0;

// ======= Ultrassom =======
float readDistanceCm() {
  digitalWrite(PIN_TRIG, LOW); delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  long duration = pulseIn(PIN_ECHO, HIGH, 30000); // timeout ~30ms
  float distance = duration * 0.0343f / 2.0f;
  if (distance <= 0 || distance > 500) return 500;
  return distance;
}

// ======= Callback MQTT (comandos) =======
void onMqtt(char* topic, byte* payload, unsigned int len) {
  String msg; msg.reserve(len);
  for (unsigned int i=0;i<len;i++) msg += (char)payload[i];

  if (String(topic) == topicCmd()) {
    if      (msg.indexOf("alarm|on")  >= 0) digitalWrite(PIN_LED, HIGH);
    else if (msg.indexOf("alarm|off") >= 0) digitalWrite(PIN_LED, LOW);
  }
}

void ensureMqtt() {
  while (!mqtt.connected()) {
    Serial.print("Tentando MQTT em: ");
    Serial.print(MQTT_HOST);
    Serial.print("...");

    if (mqtt.connect(DEVICE_ID)) {
      Serial.println(" SUCESSO! 🚀"); // <-- Adicionado SUCESSO
      mqtt.subscribe(topicCmd().c_str());
    } else {
      Serial.print(" FALHA. Código: "); // <-- Adicionado FALHA
      Serial.print(mqtt.state());
      Serial.println(". Nova tentativa em 1.5s."); 
      delay(1500);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(200); }

  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  mqtt.setCallback(onMqtt);
}

void loop() {
  ensureMqtt();

  long now = millis();
  if (now - lastSend > 5000) {
    lastSend = now;

    // ---- Leitura sensores ----
    float t = dht.readTemperature();   // °C
    float h = dht.readHumidity();      // %
    // trata leituras inválidas (NaN no primeiro(s) ciclo(s))
    if (isnan(t)) t = 0.0f;
    if (isnan(h)) h = 0.0f;

    float l = analogRead(PIN_LDR);     // 0..4095 (ESP32 ADC)
    float d = readDistanceCm();        // cm

    // ---- Publica UL 2.0 ----
    char buf[128];
    snprintf(buf, sizeof(buf), "t|%.2f|h|%.2f|l|%.0f|d|%.2f", t, h, l, d);
    mqtt.publish(topicAttrs().c_str(), buf);

    Serial.print("PUB "); Serial.print(topicAttrs());
    Serial.print(" => "); Serial.println(buf);
  }

  mqtt.loop();
}