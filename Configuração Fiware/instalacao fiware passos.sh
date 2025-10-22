# Utilizei o sudo su para fazer login de administração no Linux
# Instalei em uma máquina virtual VM Virtual Box o Ubuntu LTS, imagem do próprio site da Ubuntu
# Loguei no modo de administrador com sudo su

cd / # Indo para o diretório Raiz

apt update # Atualização das bibliotecas
apt install docker.io # Instalação do docker.io
apt install docker-compose # Instalação do docker-compose

git clone https://github.com/fabiocabrini/fiware # Clonando repositório do fiware

cd fiware # Entrando na pasta do fiware

sudo docker-compose up -d # Ligar os conteineres do docker na pasta fiware
sudo docker-compose ps # Verificar status dos conteineres
sudo docker-compose down # Desligar Conteineres

# Limpando registros do banco de dados do MongoDb
docker volume rm fiware_mongo-historical-data 

docker volume rm fiware_mongo-internal-data

# Liberação das portas TCP
ufw allow 1026 # Orion Context Broker
ufw allow 1883 # Eclipse-Mosquitto MQTT
ufw allow 4041 # IoT-Agent MQTT
ufw allow 8666 # STH-Comet
ufw allow 22 # SSH
ufw status verbose # Verificar status das portas

hostname -I # Verificar IP da máquina

sudo docker-compose up -d # Ligar os conteineres do docker na pasta fiware
sudo docker-compose ps # Verificar status dos conteineres