/*
  Project: Traffic Light Controller
  Author: Swarnava Dey
  Date: 28-06-2026
*/

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buttonPin = 7;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Using internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

// Function to switch LEDs
void setLights(bool red, bool yellow, bool green) {
  digitalWrite(redLED, red);
  digitalWrite(yellowLED, yellow);
  digitalWrite(greenLED, green);
}

// Function to print state with timestamp
void printState(String state) {
  Serial.print("Time: ");
  Serial.print(millis());
  Serial.print(" ms | Light: ");
  Serial.println(state);
}

// Check if pedestrian button is pressed
bool pedestrianRequest() {
  if (digitalRead(buttonPin) == HIGH) {
    setLights(HIGH, LOW, LOW);
    printState("PEDESTRIAN CROSSING - RED");

    delay(8000);   // Hold red for 8 seconds

    return true;
  }
  return false;
}

void loop() {

  // RED
  setLights(HIGH, LOW, LOW);
  printState("RED");

  for (int i = 0; i < 50; i++) {
    if (pedestrianRequest()) return;
    delay(100);
  }

  // YELLOW
  setLights(LOW, HIGH, LOW);
  printState("YELLOW");

  for (int i = 0; i < 20; i++) {
    if (pedestrianRequest()) return;
    delay(100);
  }

  // GREEN
  setLights(LOW, LOW, HIGH);
  printState("GREEN");

  for (int i = 0; i < 40; i++) {
    if (pedestrianRequest()) return;
    delay(100);
  }
}
