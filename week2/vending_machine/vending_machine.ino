/*
==========================================================
Project : Vending Machine State Machine
Author  : Swarnava Dey
Date    : 28-06-2026

State Transition Diagram

          Insert Coin
      +------------------+
      |                  |
      v                  |
    IDLE ------------> COIN_INSERTED
      ^                     |
      |                     |
 Cancel|                     | Select Item
      |                     v
      +-------------- ITEM_SELECTED
                           |
                           |
                           | Dispense Item
                           v
                     DISPENSING
                           |
                           | Finished
                           v
                         IDLE

Cancel can be pressed in COIN_INSERTED or
ITEM_SELECTED to return to IDLE.
==========================================================
*/

//-------------------------------
// State Definitions
//-------------------------------
enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void updateLEDs();
void changeState(State newState);
String stateName(State state);

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

const int coinButton = 2;
const int selectButton = 3;
const int cancelButton = 4;


//-------------------------------
void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(coinButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(cancelButton, INPUT_PULLUP);

  Serial.begin(9600);

  updateLEDs();
  Serial.println("System Started");
  Serial.println("Current State -> IDLE");
}

//-------------------------------
void loop() {

  switch (currentState) {

    //---------------------------
    case IDLE:

      if (digitalRead(coinButton) == LOW) {
        changeState(COIN_INSERTED);
        delay(250);
      }

      break;

    //---------------------------
    case COIN_INSERTED:

      if (digitalRead(selectButton) == LOW) {
        changeState(ITEM_SELECTED);
        delay(250);
      }

      else if (digitalRead(cancelButton) == LOW) {
        changeState(IDLE);
        delay(250);
      }

      break;

    //---------------------------
    case ITEM_SELECTED:

      // Simulate dispensing
      changeState(DISPENSING);

      delay(3000);

      changeState(IDLE);

      break;

    //---------------------------
    case DISPENSING:

      break;
  }
}

//-------------------------------
// Change State
//-------------------------------
void changeState(State newState) {

  Serial.print(stateName(currentState));
  Serial.print("  -->  ");
  Serial.println(stateName(newState));

  currentState = newState;

  updateLEDs();
}

//-------------------------------
// LED Indicators
//-------------------------------
void updateLEDs() {

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  switch (currentState) {

    case IDLE:
      digitalWrite(redLED, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(yellowLED, HIGH);
      break;

    case ITEM_SELECTED:
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, HIGH);
      break;

    case DISPENSING:
      digitalWrite(greenLED, HIGH);
      break;
  }
}

//-------------------------------
// State Names
//-------------------------------
String stateName(State state) {

  switch (state) {

    case IDLE:
      return "IDLE";

    case COIN_INSERTED:
      return "COIN_INSERTED";

    case ITEM_SELECTED:
      return "ITEM_SELECTED";

    case DISPENSING:
      return "DISPENSING";

    default:
      return "UNKNOWN";
  }
}
