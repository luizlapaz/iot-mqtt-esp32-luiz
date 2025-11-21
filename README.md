# iot-mqtt-esp32-luiz
Projeto acadêmico da disciplina Objetos Inteligentes Conectados, contendo código-fonte, documentação, esquemas e testes do sistema IoT baseado em ESP32, DHT22 e MQTT.

# Sistema IoT com ESP32, DHT22 e MQTT

Este repositório contém o projeto desenvolvido para a disciplina Objetos Inteligentes Conectados, incluindo código-fonte, documentação, diagramas e resultados de testes. O sistema foi implementado em simulação utilizando a plataforma Wokwi e integra um sensor DHT22 para coleta de temperatura e umidade, um atuador (LED) e comunicação via protocolo MQTT.

---

## 1. Hardware utilizado (simulado)

- ESP32 DevKit V1  
- Sensor DHT22  
- LED  
- Resistor 220 Ω  
- Jumpers virtuais  

---

## 2. Conexões do circuito

### DHT22
- VCC → 3V3  
- GND → GND  
- DATA → GPIO 15  

### LED
- Anodo → GPIO 2 (via resistor de 220 Ω)  
- Catodo → GND  

---

## 3. Comunicação MQTT

- Broker: test.mosquitto.org  
- Porta: 1883  
- QoS: 0  

### Tópicos utilizados
- Publicação dos dados do sensor: `oiot/luiz/sensor`  
- Controle do LED: `oiot/luiz/atuador`  

O ESP32 publica leituras no formato JSON:
{"temp": 24.40, "umid": 40.00}

O LED pode ser acionado enviando ao tópico `oiot/luiz/atuador`:

ON
ou
OFF

## 4. Funcionamento geral da solução

1. O ESP32 conecta-se ao Wi-Fi.  
2. Em seguida, conecta-se ao broker MQTT.  
3. O sensor DHT22 é lido a cada 5 segundos.  
4. Os valores são enviados ao broker.  
5. O LED é acionado automaticamente caso a temperatura seja maior ou igual a 30 °C.  
6. O LED pode ser acionado manualmente via MQTT, sobrescrevendo o comportamento automático.  

---

## 5. Testes e tempos de resposta

### Sensor → MQTT
- Medições: 9.30 s, 8.12 s, 8.58 s, 7.30 s  
- Tempo médio: 8.32 s  

### MQTT → Atuador (LED)
- Medições: 0.91 s, 0.87 s, 0.73 s, 0.93 s  
- Tempo médio: 0.86 s  

Os gráficos encontram-se na pasta `docs/graficos/`.

---

## 6. Arquivos do repositório

- `src/codigo_esp32.ino`: código-fonte completo do ESP32  
- `docs/`: imagens, diagramas, capturas de tela e gráficos  
- `README.md`: documentação principal  
- `LICENSE`: licença do projeto  

---

## 7. Execução do projeto

1. Abra o projeto no Wokwi.  
2. Configure o MQTTX utilizando o broker `test.mosquitto.org`.  
3. Assine os tópicos:
   - `oiot/luiz/sensor`
   - `oiot/luiz/atuador`
4. Publique comandos ON/OFF para testar o atuador.  

---

## 8. Licença

Este projeto está licenciado sob a licença MIT.
