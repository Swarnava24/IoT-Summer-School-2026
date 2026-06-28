/*
  Project: PWM Fading Night Light
  Author: Swarnava Dey
  Date: 28-06-2026
*/

const int ledPin = 9;        // PWM pin
const int buttonPin = 2;

int mode = 1;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  // -------- Check Button --------
  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    mode++;

    if (mode > 3)
      mode = 1;

    Serial.print("Current Mode: ");

    if (mode == 1)
      Serial.println("Slow Breathing");

    else if (mode == 2)
      Serial.println("Fast Pulse");

    else
      Serial.println("SOS Pattern");

    delay(250);      // Debounce
  }

  lastButtonState = currentButtonState;

  // -------- Run Current Mode --------

  if (mode == 1)
    slowBreathing();

  else if (mode == 2)
    fastPulse();

  else
    sosPattern();
}

//==============================
// Slow Breathing (3 sec cycle)
//==============================
void slowBreathing() {

  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(6);
    if (buttonPressed()) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(6);
    if (buttonPressed()) return;
  }
}

//==============================
// Fast Pulse (0.5 sec cycle)
//==============================
void fastPulse() {

  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(1);
    if (buttonPressed()) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(1);
    if (buttonPressed()) return;
  }
}

//==============================
// SOS Pattern
//==============================
void sosPattern() {

  // ...
  for (int i = 0; i < 3; i++) {
    flash(200);
    if (buttonPressed()) return;
  }

  delay(300);

  // ---
  for (int i = 0; i < 3; i++) {
    flash(600);
    if (buttonPressed()) return;
  }

  delay(300);

  // ...
  for (int i = 0; i < 3; i++) {
    flash(200);
    if (buttonPressed()) return;
  }

  delay(1000);
}

//==============================
void flash(int duration) {

  analogWrite(ledPin, 255);
  delay(duration);

  analogWrite(ledPin, 0);
  delay(200);
}

//==============================
bool buttonPressed() {

  bool state = digitalRead(buttonPin);

  if (lastButtonState == HIGH && state == LOW) {

    mode++;

    if (mode > 3)
      mode = 1;

    Serial.print("Current Mode: ");

    if (mode == 1)
      Serial.println("Slow Breathing");

    else if (mode == 2)
      Serial.println("Fast Pulse");

    else
      Serial.println("SOS Pattern");

    delay(250);

    lastButtonState = LOW;
    return true;
  }

  lastButtonState = state;
  return false;
}

