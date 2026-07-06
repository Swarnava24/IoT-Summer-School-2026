# Vending Machine State Machine

## Project Overview

This project simulates the operation of a **vending machine** using an Arduino Uno and implements a **Finite State Machine (FSM)**. The machine transitions through different operational states based on user inputs such as inserting a coin, selecting an item, or cancelling the transaction. Three LEDs indicate the current state of the vending machine, while the Serial Monitor displays state transitions.

---

## Objectives

* Understand the concept of a Finite State Machine (FSM).
* Simulate a vending machine using Arduino.
* Implement state transitions based on button inputs.
* Indicate machine status using LEDs.
* Display state changes on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* 3 × Push Buttons
* 3 × LEDs (Red, Yellow, Green)
* 3 × 220Ω Resistors
* Breadboard
* Jumper Wires

> **Note:** The push buttons use Arduino's **internal pull-up resistors**, so no external resistors are required.

---

## Circuit Connections

### LEDs

| LED        | Arduino Pin |
| ---------- | ----------- |
| Red LED    | D8          |
| Yellow LED | D9          |
| Green LED  | D10         |

Each LED should be connected through a **220Ω resistor** to GND.

### Push Buttons

| Button        | Function           | Arduino Pin |
| ------------- | ------------------ | ----------- |
| Coin Button   | Insert Coin        | D2          |
| Select Button | Select Item        | D3          |
| Cancel Button | Cancel Transaction | D4          |

Each push button connects between the Arduino pin and **GND** because the sketch uses `INPUT_PULLUP`.

---

## Finite State Machine

The vending machine consists of four states:

| State             | Description                                            |
| ----------------- | ------------------------------------------------------ |
| **IDLE**          | Waiting for the user to insert a coin.                 |
| **COIN_INSERTED** | Coin accepted; waiting for item selection.             |
| **ITEM_SELECTED** | Item selected; preparing to dispense.                  |
| **DISPENSING**    | Dispensing the selected item before returning to IDLE. |

---

## State Transition Diagram

```text
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

Cancel can be pressed in COIN_INSERTED
to return to IDLE.
```

---

## LED Indications

| State         | Red | Yellow | Green |
| ------------- | :-: | :----: | :---: |
| IDLE          |  ✅  |    ❌   |   ❌   |
| COIN_INSERTED |  ❌  |    ✅   |   ❌   |
| ITEM_SELECTED |  ✅  |    ✅   |   ❌   |
| DISPENSING    |  ❌  |    ❌   |   ✅   |

---

## Working Principle

1. The system starts in the **IDLE** state.
2. Pressing the **Coin** button changes the state to **COIN_INSERTED**.
3. Pressing the **Select** button changes the state to **ITEM_SELECTED**.
4. The machine automatically enters the **DISPENSING** state for 3 seconds.
5. After dispensing, it returns to the **IDLE** state.
6. Pressing the **Cancel** button while in **COIN_INSERTED** returns the system to **IDLE**.
7. Every state transition is displayed on the Serial Monitor.

---

## Features

* Finite State Machine implementation.
* Four operational vending machine states.
* LED indication for each state.
* Push-button controlled state transitions.
* Automatic dispensing simulation.
* Serial Monitor logging of state changes.

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno using a USB cable.
3. Open the project sketch.
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify** to compile the sketch.
6. Click **Upload**.
7. Open the **Serial Monitor** at **9600 baud**.

---

## Expected Output

### Serial Monitor

```text
System Started
Current State -> IDLE

IDLE  -->  COIN_INSERTED
COIN_INSERTED  -->  ITEM_SELECTED
ITEM_SELECTED  -->  DISPENSING
DISPENSING  -->  IDLE
```

If the **Cancel** button is pressed:

```text
IDLE  -->  COIN_INSERTED
COIN_INSERTED  -->  IDLE
```

## Future Improvements

* Add an LCD display to show available products and prices.
* Support multiple item selections.
* Simulate coin values and balance calculation.
* Add a buzzer for user feedback.
* Store sales data in EEPROM or an SD card.
* Replace delays with `millis()` for non-blocking operation.

---

## Author

**Swarnava Dey**
