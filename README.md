# CP5-Edge-Computing-Vinheria

Gabriel dos Santos Hemeterio
RM566243
gabriel.hemeterio13@gmail.com

Alana Vieira Batista
RM563796
alanavieirabatista21@gmail.com

Kawan Oliveira Amorim
RM56197
oliveirakawan039@gmail.com

Matheus Hideki Doroszewski Yoshimura
RM564970
mathideki06@gmail.com

Felippe Nascimento Silva
RM562123

Resutados do PoC:

Health Check:
{
    "libVersion": "4.7.0",
    "port": "4041",
    "baseRoot": "/",
    "version": "3.7.0"
}
Provisioning a Service Group for MQTT:
{
    "name": "DUPLICATE_GROUP",
    "message": "A device configuration already exists for resource  and API Key TEF and {\"apikey\":\"TEF\",\"cbroker\":\"http://9.234.138.146:1026\",\"resource\":\"\",\"type\":\"Thing\",\"service\":\"smart\",\"subservice\":\"/\"}"
}
2.1 Health Check Services:
{
    "count": 1,
    "services": [
        {
            "commands": [],
            "lazy": [],
            "attributes": [],
            "_id": "68e57c9021097e112b096e86",
            "resource": "",
            "apikey": "TEF",
            "service": "smart",
            "subservice": "/",
            "__v": 0,
            "static_attributes": [],
            "internal_attributes": [],
            "entity_type": "Thing"
        }
    ]
}
2.1 Delete a Service Group: HTTP STATUS 204

Provisioning a Smart Lamp:
{
    "name": "DUPLICATE_DEVICE_ID",
    "message": "A device with the same info (DeviceId, ApiKey, Service, Subservice) was found:lamp001 and {\"id\":\"lamp001\",\"type\":\"Lamp\",\"name\":\"urn:ngsi-ld:Lamp:001\",\"service\":\"smart\",\"subservice\":\"/\",\"active\":[{\"object_id\":\"s\",\"name\":\"state\",\"type\":\"Text\"},{\"object_id\":\"l\",\"name\":\"luminosity\",\"type\":\"Integer\"}],\"commands\":[{\"name\":\"on\",\"type\":\"command\"},{\"name\":\"off\",\"type\":\"command\"}],\"protocol\":\"PDI-IoTA-UltraLight\",\"transport\":\"MQTT\",\"internalId\":null}"
}
List all Devices Provisioned:
{
    "count": 3,
    "devices": [
        {
            "device_id": "lamp001",
            "service": "smart",
            "service_path": "/",
            "entity_name": "urn:ngsi-ld:Lamp:001",
            "entity_type": "Lamp",
            "transport": "MQTT",
            "attributes": [
                {
                    "object_id": "s",
                    "name": "state",
                    "type": "Text"
                },
                {
                    "object_id": "l",
                    "name": "luminosity",
                    "type": "Integer"
                }
            ],
            "lazy": [],
            "commands": [
                {
                    "object_id": "on",
                    "name": "on",
                    "type": "command"
                },
                {
                    "object_id": "off",
                    "name": "off",
                    "type": "command"
                }
            ],
            "static_attributes": [],
            "protocol": "PDI-IoTA-UltraLight"
        },
        {
            "device_id": "lamp022",
            "service": "smart",
            "service_path": "/",
            "entity_name": "urn:ngsi-ld:Lamp:022",
            "entity_type": "Lamp",
            "transport": "MQTT",
            "attributes": [
                {
                    "object_id": "s",
                    "name": "state",
                    "type": "Text"
                },
                {
                    "object_id": "l",
                    "name": "luminosity",
                    "type": "Integer"
                }
            ],
            "lazy": [],
            "commands": [
                {
                    "object_id": "on",
                    "name": "on",
                    "type": "command"
                },
                {
                    "object_id": "off",
                    "name": "off",
                    "type": "command"
                }
            ],
            "static_attributes": [],
            "protocol": "PDI-IoTA-UltraLight"
        },
        {
            "device_id": "lamp002",
            "service": "smart",
            "service_path": "/",
            "entity_name": "urn:ngsi-ld:Lamp:002",
            "entity_type": "Lamp",
            "transport": "MQTT",
            "attributes": [
                {
                    "object_id": "s",
                    "name": "state",
                    "type": "Text"
                },
                {
                    "object_id": "l",
                    "name": "luminosity",
                    "type": "Integer"
                },
                {
                    "object_id": "t",
                    "name": "luminosity",
                    "type": "Float"
                },
                {
                    "object_id": "h",
                    "name": "humidity",
                    "type": "Float"
                }
            ],
            "lazy": [],
            "commands": [
                {
                    "object_id": "on",
                    "name": "on",
                    "type": "command"
                },
                {
                    "object_id": "off",
                    "name": "off",
                    "type": "command"
                }
            ],
            "static_attributes": [],
            "protocol": "PDI-IoTA-UltraLight"
        }
    ]
}
