#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

#define DHT_PIN 15
#define LED_PIN 2

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

const char* mqtt_client_id = "luiz_esp32_oiot";
const char* topic_sensor = "oiot/luiz/sensor";
const char* topic_atuador = "oiot/luiz/atuador";

WiFiClient espClient;
PubSubClient client(espClient);
DHTesp dht;

unsigned long lastMsg = 0;
const long interval = 5000;
bool manualOverride = false;

void setup_wifi() {
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) msg += (char)message[i];

  if (String(topic) == topic_atuador) {
    manualOverride = true;
    if (msg == "ON") digitalWrite(LED_PIN, HIGH);
    else if (msg == "OFF") digitalWrite(LED_PIN, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(mqtt_client_id)) {
      client.subscribe(topic_atuador);
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.setup(DHT_PIN, DHTesp::DHT22);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > interval) {
    lastMsg = now;
    TempAndHumidity data = dht.getTempAndHumidity();

    float temp = data.temperature;
    float hum = data.humidity;

    String payload = "{\"temp\":" + String(temp, 2) + ",\"umid\":" + String(hum, 2) + "}";
    client.publish(topic_sensor, payload.c_str());

    if (!manualOverride) {
      if (temp >= 30.0) digitalWrite(LED_PIN, HIGH);
      else digitalWrite(LED_PIN, LOW);
    }
  }
}
