#include <Arduino.h>

#define LDR_PIN 34
#define LED_PIN 14
#define N 5

int buf[N] = {0};
int idx = 0, sum = 0;

int smooth(int val) {
  sum -= buf[idx];
  buf[idx] = val;
  sum += val;
  idx = (idx + 1) % N;
  return sum / N;
}

void logVitals(int hr, int spo2, bool alert) {
  Serial.println("--------------------------");
  Serial.print("Heart Rate : "); Serial.print(hr); Serial.println(" bpm");
  Serial.print("SpO2 : "); Serial.print(spo2); Serial.println(" %");
  Serial.print("Alert : "); Serial.println(alert ? "YES" : "NO");
  Serial.println("--------------------------");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int avg = smooth(analogRead(LDR_PIN));

  int hr    = map(avg, 0, 4095, 40, 140);
  int spo2  = map(avg, 0, 4095, 88, 100);
  bool alert = (hr < 50 || hr > 120 || spo2 < 94);

  digitalWrite(LED_PIN, alert ? HIGH : LOW);
  logVitals(hr, spo2, alert);

  delay(2000);
}
