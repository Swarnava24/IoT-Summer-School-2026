/*
Author: Swarnava Dey
Date: 28-06-2026
Description: Arduino LED blink project with serial output and potentiometer-controlled blink speed.
*/

int blinkCount = 0;
const int ledPin = 13;
const int sensorPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read potentiometer value (0-1023)
  int sensorValue = analogRead(sensorPin);

  // Map to a useful delay range (100-1000 ms)
  int delayTime = map(sensorValue, 0, 1023, 100, 1000);

  digitalWrite(ledPin, HIGH);
  delay(delayTime);

  digitalWrite(ledPin, LOW);
  delay(delayTime);

  blinkCount++;

  Serial.print("Blink count: ");
  Serial.print(blinkCount);
  Serial.print(", Delay: ");
  Serial.print(delayTime);
  Serial.println(" ms");
}
