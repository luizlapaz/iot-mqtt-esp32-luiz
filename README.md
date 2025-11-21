# iot-mqtt-esp32-luiz
Projeto acadêmico da disciplina Objetos Inteligentes Conectados, contendo código-fonte, documentação, esquemas e testes do sistema IoT baseado em ESP32, DHT22 e MQTT.

# Sistema IoT com ESP32, DHT22 e Protocolo MQTT

Este repositório contém o projeto desenvolvido para a disciplina Objetos Inteligentes Conectados. O sistema consiste em um protótipo IoT capaz de realizar a leitura de temperatura e umidade por meio do sensor DHT22, publicar esses dados em um broker MQTT e permitir o acionamento remoto de um atuador (LED) tanto automaticamente quanto via comando MQTT.

Toda a implementação foi realizada na plataforma de simulação Wokwi.

---

## 1. Objetivo do Projeto

O objetivo do projeto é demonstrar a construção de um sistema IoT funcional, integrando sensores, atuadores, conectividade via Wi-Fi e comunicação MQTT, de forma a cumprir todos os requisitos da disciplina, incluindo documentação, testes, gráficos, fluxograma e armazenamento em repositório público.

---

## 2. Hardware Utilizado (Simulado)

- ESP32 DevKit V1  
- Sensor DHT22  
- LED  
- Resistor de 220 Ω  
- Jumpers virtuais  
- Ambiente de simulação: Wokwi  

---

## 3. Conexões do Circuito

### DHT22
| Pino DHT22 | Pino ESP32 |
|-----------|-------------|
| VCC       | 3V3         |
| GND       | GND         |
| DATA      | GPIO 15     |

### LED (Atuador)
| Pino LED     | Pino ESP32 |
|--------------|-------------|
| Anodo (+)    | GPIO 2 (via resistor de 220 Ω) |
| Catodo (–)   | GND |

A imagem completa do circuito está disponível em `docs/`.

---

## 4. Comunicação MQTT

- Broker: `test.mosquitto.org`  
- Porta: 1883  
- Cliente MQTT usado para testes: MQTTX  
- QoS: 0

### Tópicos utilizados

| Função                  | Tópico               |
|------------------------|----------------------|
| Publicação do sensor   | oiot/luiz/sensor     |
| Controle do atuador    | oiot/luiz/atuador    |

### Formato da mensagem publicada pelo sensor

```json
{"temp": 24.40, "umid": 40.00}
```

### Comandos aceitos pelo atuador
```
ON
OFF
```

---

## 5. Funcionamento do Sistema

1. O ESP32 conecta-se à rede Wi-Fi.  
2. Em seguida, estabelece conexão com o broker MQTT.  
3. O sensor DHT22 é lido a cada 5 segundos.  
4. Os dados são enviados ao tópico `oiot/luiz/sensor` em formato JSON.  
5. O LED acende automaticamente se a temperatura for maior ou igual a 30 °C.  
6. O LED pode ser acionado manualmente via MQTT, sobrescrevendo o funcionamento automático.  
7. Todos os comandos manuais são tratados pela função de callback do MQTT.

---

## 6. Testes e Tempo de Resposta

Quatro medições foram realizadas para cada componente:

### Sensor → MQTT
- Valores: 9.30 s, 8.12 s, 8.58 s, 7.30 s  
- Média: 8.32 s  

### MQTT → Atuador
- Valores: 0.91 s, 0.87 s, 0.73 s, 0.93 s  
- Média: 0.86 s  

Os gráficos desses resultados encontram-se na pasta `docs/graficos/`.

---

## 7. Estrutura do Repositório

```
iot-mqtt-esp32-luiz/
│
├── README.md
├── LICENSE
│
├── src/
│   └── codigo_esp32.ino
│
└── docs/
    ├── circuito_completo_mqtt_atuador.png
    ├── console_auto_led_desligado.png
    ├── console_auto_led_ligado.png
    ├── grafico_atuador.png
    ├── grafico_sensor.png
    ├── mqtt_atuador_on_off.png
    ├── mqtt_sensor_recebido.png
    └── fluxograma_funcionamento.png
```

---

## 8. Execução e Reprodução do Projeto

1. Acesse o projeto no Wokwi (link no artigo).  
2. Configure o MQTTX usando o broker `test.mosquitto.org`.  
3. Assine os tópicos:
   - `oiot/luiz/sensor`
   - `oiot/luiz/atuador`  
4. Ligue e desligue o LED enviando:
   - `ON`
   - `OFF`  
5. Observe os dados publicados pelo sensor em tempo real.

---

## 9. Licença

Este projeto está licenciado sob a licença MIT.
