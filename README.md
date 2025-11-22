# iot-mqtt-esp32-luiz
Projeto acadêmico da disciplina Objetos Inteligentes Conectados, contendo código-fonte, documentação, esquemas e testes do sistema IoT baseado em ESP32, DHT22 e MQTT.

# Sistema IoT com ESP32, Sensor DHT22 e Protocolo MQTT
Autor: Luiz Henrique de Lapaz  
Disciplina: Objetos Inteligentes Conectados  
Professor: Wilian França Costa  
Ano: 2025

---

## 1. Descrição do Projeto

Este projeto implementa um sistema IoT utilizando:

- ESP32 como microcontrolador principal  
- Sensor DHT22 para leitura de temperatura e umidade  
- LED como atuador  
- Comunicação baseada no protocolo MQTT  
- Simulação completa utilizando a plataforma Wokwi  
- Monitoramento e testes com o cliente MQTTX  

O sistema realiza leitura periódica do sensor, publica os valores em um tópico MQTT, recebe comandos de outro tópico e aciona o LED tanto automaticamente quanto manualmente.

---

## 2. Arquitetura do Sistema

O funcionamento segue as etapas:

1. Inicialização do ESP32  
2. Conexão ao Wi-Fi  
3. Conexão ao broker MQTT  
4. Leitura dos valores do DHT22  
5. Publicação em JSON no tópico do sensor  
6. Leitura de comandos MQTT para o atuador  
7. Acionamento do LED  
8. Repetição do ciclo principal  

O fluxograma completo está no arquivo:
docs/fluxograma_funcionamento.png

---

## 3. Organização do Repositório

iot-mqtt-esp32-luiz/
│
├── artigo_final/
│ ├── artigo_IoT.pdf
│ └── txt.txt
│
├── docs/
│ ├── circuito_completo_mqtt_atuador.png
│ ├── console_auto_led_desligado.png
│ ├── console_auto_led_ligado.png
│ ├── fluxograma_funcionamento.png
│ ├── grafico_atuador.png
│ ├── grafico_sensor.png
│ ├── mqtt_atuador_on_off.png
│ └── mqtt_sensor_recebido.png
│
├── src/
│ └── codigo_esp32.ino
│
├── LICENSE
└── README.md


---

## 4. Simulação do Projeto

Simulação completa do circuito disponível em:

https://wokwi.com/projects/448247854347970561

---

## 5. Tópicos MQTT Utilizados

Tópico para envio dos dados do sensor:  
`oiot/luiz/sensor`

Tópico para comandos enviados ao atuador:  
`oiot/luiz/atuador`

Broker MQTT utilizado:  
`test.mosquitto.org:1883`

---

## 6. Código-Fonte

O código principal do projeto está em:

src/codigo_esp32.ino

Contém:

- Configuração de Wi-Fi  
- Conexão ao broker MQTT  
- Callback do atuador  
- Leitura do DHT22  
- Publicação em formato JSON  
- Acionamento automático do LED  
- Controle manual via MQTT  

---

## 7. Resultados Obtidos

As evidências e imagens geradas durante os testes estão em:

docs/

Imagens incluídas:

- circuito_completo_mqtt_atuador.png  
- console_auto_led_ligado.png  
- console_auto_led_desligado.png  
- mqtt_atuador_on_off.png  
- mqtt_sensor_recebido.png  
- grafico_sensor.png  
- grafico_atuador.png  
- fluxograma_funcionamento.png  

---

## 8. Artigo Final

O artigo técnico desenvolvido para o projeto está disponível em:

artigo_final/artigo_IoT.pdf

---

## 9. Vídeo de Demonstração

O vídeo deve conter:

- Identificação do aluno  
- Demonstração da simulação  
- Funcionamento MQTT em tempo real  
- Explicação do código  

Link do vídeo (adicionar após upload):  
[Inserir aqui]

---

## 10. Licença

Este projeto está sob a licença MIT. O arquivo LICENSE está incluído no repositório.
