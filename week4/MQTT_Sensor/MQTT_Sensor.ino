/*
-------------------------------------------------------
Project: MQTT Sensor Publisher
Author: Swarnava Dey
Date: 06-07-2026

Description:
- Connects ESP32 to Wi-Fi.
- Reads temperature and humidity from a DHT22 sensor
- Publishes sensor readings every 5 seconds in JSON
  format to an MQTT broker.
- Subscribes to an LED control topic.
- Toggles the onboard LED based on MQTT messages.
-------------------------------------------------------
*/

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "DHTesp.h"

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

DHTesp dht;

const int DHT_PIN = 15;
const int LED_PIN = 2;

// Change YourName to your own name
const char* tempTopic = "iitjammu/summer26/SwarnavaDey/temperature";
const char* humTopic  = "iitjammu/summer26/SwarnavaDey/humidity";
const char* ledTopic  = "iitjammu/summer26/SwarnavaDey/led_control";

void callback(char* topic, byte* payload, unsigned int length) {

  String msg;

  for (int i = 0; i < length; i++)
    msg += (char)payload[i];

  Serial.print("Received: ");
  Serial.println(msg);

  if (msg == "ON") {

    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");

  }

  else if (msg == "OFF") {

    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");

  }

}

void reconnect() {

  while (!client.connected()) {

    Serial.print("Connecting MQTT...");

    if (client.connect("ESP32Client")) {

      Serial.println("Connected");

      client.subscribe(ledTopic);

    }

    else {

      Serial.print("Failed, rc=");
      Serial.println(client.state());

      delay(2000);

    }

  }

}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.setup(DHT_PIN, DHTesp::DHT22);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }

  Serial.println("\nWiFi Connected");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {

  if (!client.connected())
    reconnect();

  client.loop();

  static unsigned long lastPublish = 0;

  if (millis() - lastPublish > 5000) {

    lastPublish = millis();

    TempAndHumidity data = dht.getTempAndHumidity();

    StaticJsonDocument<128> doc;

    doc["value"] = data.temperature;
    doc["unit"] = "C";
    doc["ts"] = millis();

    char buffer[128];

    serializeJson(doc, buffer);

    client.publish(tempTopic, buffer);

    doc.clear();

    doc["value"] = data.humidity;
    doc["unit"] = "%";
    doc["ts"] = millis();

    serializeJson(doc, buffer);

    client.publish(humTopic, buffer);

    Serial.println("Published Temperature");

    Serial.println(buffer);

  }

}
