
---

# iot-mqtt-esp32-luiz

Projeto acadêmico desenvolvido na disciplina **Objetos Inteligentes Conectados**, implementando um sistema IoT com ESP32, sensor DHT22 e comunicação via MQTT. Inclui código-fonte, documentação, esquemas, gráficos, fluxograma, simulação Wokwi e artigo final.

# Sistema IoT com ESP32, Sensor DHT22 e Protocolo MQTT

**Autor:** Luiz Henrique de Lapaz

**Disciplina:** Objetos Inteligentes Conectados

**Professor:** Wilian França Costa

**Ano:** 2025

---

## 1. Descrição do Projeto

Este projeto apresenta a implementação de um sistema IoT composto por:

* ESP32 como microcontrolador principal
* Sensor DHT22 para leitura de temperatura e umidade
* LED como atuador
* Comunicação MQTT (publish/subscribe)
* Simulação completa no Wokwi
* Testes MQTT com o cliente MQTTX

O sistema lê periodicamente o sensor, publica dados em formato JSON, recebe comandos MQTT e controla o LED automaticamente conforme temperatura ou manualmente via mensagens MQTT.

---

## 2. Arquitetura do Sistema

O funcionamento do sistema segue as seguintes etapas:

1. Inicialização do ESP32 e configuração dos pinos
2. Conexão ao Wi-Fi
3. Conexão ao broker MQTT
4. Inscrição no tópico do atuador
5. Leitura do DHT22 a cada 5 segundos
6. Publicação dos dados em JSON
7. Acionamento automático do LED caso a temperatura seja ≥ 30 ºC
8. Controle manual via MQTT sobrescrevendo o automático
9. Repetição contínua do loop principal

Fluxograma disponível em:
`docs/fluxograma_funcionamento.png`

---

## 3. Organização do Repositório

Estrutura atual do projeto:

iot-mqtt-esp32-luiz/

• artigo_final/

 • artigo_IoT.pdf
 
• docs/

 • circuito_completo.png
 
 • circuito_completo_mqtt_atuador.png
 
 • console_auto_led_desligado.png
 
 • console_auto_led_ligado.png
 
 • fluxograma_funcionamento.png
 
 • grafico_atuador.png
 
 • grafico_sensor.png
 
 • mqtt_atuador_on_off.png
 
 • mqtt_sensor_recebido.png


• src/

 • codigo_esp32.ino
 
• LICENSE

• README.md


---

## 4. Conexões do Circuito

### DHT22

* VCC → 3V3
* GND → GND
* DATA → GPIO 15

### LED (Atuador)

* Ânodo (+) → GPIO 2 (via resistor de 220 Ω)
* Cátodo (–) → GND

Imagem completa do circuito:
`docs/circuito_completo.png`

---

## 5. Comunicação MQTT

**Broker:** test.mosquitto.org
**Porta:** 1883
**Cliente para testes:** MQTTX
**QoS:** 0

### Tópicos Utilizados

* Publicação do sensor: `oiot/luiz/sensor`
* Comandos do atuador: `oiot/luiz/atuador`

### Formato JSON publicado

{"temp": 24.40, "umid": 40.00}

### Comandos aceitos (atuador)

ON
OFF

---

## 6. Funcionamento do Sistema

1. O ESP32 conecta ao Wi-Fi
2. Conecta ao broker MQTT
3. Lê o DHT22 periodicamente
4. Publica temperatura e umidade no tópico do sensor
5. Liga automaticamente o LED quando temperatura ≥ 30°C
6. Aceita comandos manuais via MQTT
7. Comandos são recebidos pela função callback
8. Continua publicando e respondendo em loop

---

## 7. Testes e Tempo de Resposta

Quatro medições foram realizadas para cada caso.

### Sensor → MQTT

Valores: 9.30 s, 8.12 s, 8.58 s, 7.30 s
Média: 8.32 s

### MQTT → Atuador

Valores: 0.91 s, 0.87 s, 0.73 s, 0.93 s
Média: 0.86 s

Gráficos dos resultados:
• docs/grafico_sensor.png
• docs/grafico_atuador.png

---

## 8. Evidências e Imagens de Funcionamento

Todos os prints do sistema estão em `docs/`, incluindo:

* circuito_completo_mqtt_atuador.png
* console_auto_led_ligado.png
* console_auto_led_desligado.png
* mqtt_atuador_on_off.png
* mqtt_sensor_recebido.png
* fluxograma_funcionamento.png
* gráficos de desempenho

---

## 9. Artigo Final

O artigo técnico entregue na disciplina está em:
`artigo_final/artigo_IoT.pdf`

---

## 10. Simulação Wokwi

Simulação completa do circuito e código:
[https://wokwi.com/projects/448247854347970561](https://wokwi.com/projects/448247854347970561)

---

## 11. Vídeo de Demonstração

O vídeo deve conter:

* Identificação do aluno
* Demonstração completa do sistema
* Testes MQTT (envio e recebimento)
* Explicação do código
* Funcionamento automático

Link do vídeo (a adicionar):
[Inserir link aqui]

---

## 12. Licença

Este projeto é distribuído sob licença MIT.

---
