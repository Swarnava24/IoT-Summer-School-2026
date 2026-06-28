/*
-------------------------------------------------------
Project: Environmental Monitoring Station
Author: Swarnava Dey
Date: 28-06-2026

Reads:
- Temperature (°C)
- Temperature (°F)
- Humidity

Outputs CSV:
timestamp,temp_C,temp_F,humidity

LED Indicators:
Red   -> Temperature >55°C OR Humidity >80%
Green -> Normal Conditions
-------------------------------------------------------
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const int redLED = 8;
const int greenLED = 9;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  if (isnan(tempC) || isnan(tempF) || isnan(humidity)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  Serial.print(millis());
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);

  if (tempC > 55 || humidity > 80) {

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

  }
  else {

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

  }

  delay(2000);
}
