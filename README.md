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
|
+-- artigo_final/
|   +-- artigo_IoT.pdf
|
+-- docs/
|   +-- circuito_completo.png
|   +-- circuito_completo_mqtt_atuador.png
|   +-- console_auto_led_desligado.png
|   +-- console_auto_led_ligado.png
|   +-- fluxograma_funcionamento.png
|   +-- grafico_atuador.png
|   +-- grafico_sensor.png
|   +-- mqtt_atuador_on_off.png
|   +-- mqtt_sensor_recebido.png
|
+-- src/
|   +-- codigo_esp32.ino
|
+-- LICENSE
+-- README.md


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



Claro — revisei **todo o seu README**, corrigi a árvore do repositório para funcionar corretamente em Markdown, incluí **as tabelas, detalhes técnicos, conexões do circuito, comunicação MQTT, testes**, e deixei tudo **formal, limpo e coerente**, seguindo exatamente o que você pediu.

Aqui está a **versão final, pronta para colar no GitHub**:

---

````markdown
# iot-mqtt-esp32-luiz
Projeto acadêmico desenvolvido na disciplina **Objetos Inteligentes Conectados**, implementando um sistema IoT com ESP32, sensor DHT22 e comunicação via MQTT. Inclui documentação completa, código-fonte, imagens, gráficos, fluxograma e artigo final.

# Sistema IoT com ESP32, Sensor DHT22 e Protocolo MQTT
**Autor:** Luiz Henrique de Lapaz  
**Disciplina:** Objetos Inteligentes Conectados  
**Professor:** Wilian França Costa  
**Ano:** 2025  

---

## 1. Descrição do Projeto

Este projeto apresenta a construção de um sistema IoT utilizando:

- ESP32 como microcontrolador principal  
- Sensor **DHT22** para leitura de temperatura e umidade  
- LED como atuador  
- Comunicação MQTT através do broker público Mosquitto  
- Simulação completa utilizando **Wokwi**  
- Testes MQTT utilizando o cliente **MQTTX**

O sistema publica periodicamente dados do sensor em formato JSON e recebe comandos via MQTT para controle do LED, que pode operar de forma automática ou manual.

---

## 2. Arquitetura do Sistema

O funcionamento segue as etapas:

1. Inicialização do ESP32 e configuração de GPIOs  
2. Conexão à rede Wi-Fi  
3. Conexão ao broker MQTT  
4. Inscrição no tópico do atuador  
5. Leitura periódica do DHT22  
6. Envio dos valores ao tópico MQTT do sensor  
7. Ação automática do LED conforme temperatura lida  
8. Sobrescrição manual via comandos MQTT  
9. Repetição do ciclo principal

O fluxograma completo do funcionamento está disponível em:
`docs/fluxograma_funcionamento.png`

---

## 3. Organização do Repositório

```plaintext
iot-mqtt-esp32-luiz/
├── artigo_final/
│   └── artigo_IoT.pdf
│
├── docs/
│   ├── circuito_completo.png
│   ├── circuito_completo_mqtt_atuador.png
│   ├── console_auto_led_desligado.png
│   ├── console_auto_led_ligado.png
│   ├── fluxograma_funcionamento.png
│   ├── grafico_atuador.png
│   ├── grafico_sensor.png
│   ├── mqtt_atuador_on_off.png
│   └── mqtt_sensor_recebido.png
│
├── src/
│   └── codigo_esp32.ino
│
├── LICENSE
└── README.md
````

---

## 4. Conexões do Circuito

### **DHT22**

| Pino DHT22 | Pino ESP32 |
| ---------- | ---------- |
| VCC        | 3V3        |
| GND        | GND        |
| DATA       | GPIO 15    |

### **LED (Atuador)**

| Pino LED   | Pino ESP32 e Componentes    |
| ---------- | --------------------------- |
| Ânodo (+)  | GPIO 2 (via resistor 220 Ω) |
| Cátodo (–) | GND                         |

A imagem completa do circuito está em:
`docs/circuito_completo.png`

---

## 5. Comunicação MQTT

* **Broker:** `test.mosquitto.org`
* **Porta:** 1883
* **Cliente para testes:** MQTTX
* **QoS:** 0

### Tópicos utilizados

| Função               | Tópico              |
| -------------------- | ------------------- |
| Publicação do sensor | `oiot/luiz/sensor`  |
| Controle do atuador  | `oiot/luiz/atuador` |

### Formato da mensagem publicada

```json
{"temp": 24.40, "umid": 40.00}
```

### Comandos aceitos pelo atuador

```
ON
OFF
```

---

## 6. Funcionamento do Sistema

1. O ESP32 conecta-se à rede Wi-Fi.
2. Estabelece conexão com o broker MQTT.
3. O DHT22 é lido a cada 5 segundos.
4. Os dados são publicados em `oiot/luiz/sensor`.
5. O LED acende automaticamente sempre que a temperatura ≥ 30 °C.
6. O sistema aceita comandos manuais via MQTT no tópico `oiot/luiz/atuador`.
7. O callback MQTT trata os comandos recebidos.
8. O ciclo repete continuamente.

---

## 7. Testes e Tempo de Resposta

Foram realizadas **quatro medições** para cada etapa:

### **Sensor → MQTT**

* 9.30 s
* 8.12 s
* 8.58 s
* 7.30 s
* **Média:** 8.32 s

### **MQTT → Atuador**

* 0.91 s
* 0.87 s
* 0.73 s
* 0.93 s
* **Média:** 0.86 s

Os gráficos dos resultados estão em:

* `docs/grafico_sensor.png`
* `docs/grafico_atuador.png`

---

## 8. Imagens e Evidências do Sistema

As imagens geradas durante os testes estão organizadas em:

`docs/`

Incluindo:

* circuito_completo.png
* circuito_completo_mqtt_atuador.png
* console_auto_led_ligado.png
* console_auto_led_desligado.png
* mqtt_atuador_on_off.png
* mqtt_sensor_recebido.png
* fluxograma_funcionamento.png
* gráficos de desempenho

---

## 9. Artigo Final do Projeto

O artigo técnico em formato PDF está disponível em:

`artigo_final/artigo_IoT.pdf`

---

## 10. Simulação Online

A simulação completa no Wokwi pode ser acessada em:

[https://wokwi.com/projects/448247854347970561](https://wokwi.com/projects/448247854347970561)

---

## 11. Vídeo de Demonstração

O vídeo deve apresentar:

* Identificação do aluno
* Demonstração da simulação
* Recebimento de mensagens MQTT
* Envio de comandos ao atuador
* Funcionamento automático do LED
* Explicação do código

Link do vídeo (adicionar após upload):
**[Adicionar link aqui]**

---

## 12. Licença

Este projeto está sob a licença **MIT**.
O arquivo LICENSE está incluído no repositório.

```


