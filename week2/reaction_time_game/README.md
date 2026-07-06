# Reaction Time Game

## Project Overview

The **Reaction Time Game** is an Arduino-based project that measures a player's reaction speed. Before each round, the Red, Green, and Blue LEDs blink in a random sequence to create anticipation. After a random delay, the Green LED lights up, signaling the player to press the push button as quickly as possible. The Arduino records the reaction time using the `millis()` function and displays the result on the Serial Monitor.

---

## Objectives

* Measure human reaction time using Arduino.
* Generate random LED patterns and delays.
* Use `millis()` for accurate time measurement.
* Read push button input.
* Display results on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* 1 × Red LED
* 1 × Green LED
* 1 × Blue LED
* 3 × 220Ω Resistors
* 1 × Push Button
* 10kΩ Pull-down Resistor *(or use an internal pull-up if modifying the code)*
* Breadboard
* Jumper Wires

---

## Circuit Connections

### LEDs

| Component | Arduino Pin |
| --------- | ----------- |
| Red LED   | D3          |
| Green LED | D5          |
| Blue LED  | D6          |

Each LED should be connected through a **220Ω resistor** to GND.

### Push Button

| Component   | Arduino Pin |
| ----------- | ----------- |
| Push Button | D2          |

One side of the button connects to **5V**, and the other side connects to **D2** with a **10kΩ pull-down resistor** to GND.

---

## Working Principle

1. All LEDs are initially turned OFF.
2. A new game round begins after a short delay.
3. The Arduino blinks random LEDs with random durations.
4. A random waiting period (0.5–2 seconds) is added.
5. The Green LED turns ON and the timer starts using `millis()`.
6. The player presses the push button as quickly as possible.
7. The reaction time is calculated and displayed on the Serial Monitor.
8. The process repeats for the next round.

---

## Features

* Random LED blinking sequence.
* Random delay before the start signal.
* Accurate reaction time measurement using `millis()`.
* Serial Monitor displays reaction time in milliseconds.
* Continuous gameplay with multiple rounds.

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
Reaction Time Game
Wait for the GREEN LED and press the button!

New Round Starting...
GO!
Reaction Time: 284 ms

New Round Starting...
GO!
Reaction Time: 197 ms

New Round Starting...
GO!
Reaction Time: 321 ms
```

---

## Game Flow

```text
Start
   │
   ▼
Random LED Blinking
   │
   ▼
Random Delay
   │
   ▼
Green LED ON
   │
   ▼
Start Timer (millis)
   │
   ▼
Wait for Button Press
   │
   ▼
Calculate Reaction Time
   │
   ▼
Display Result
   │
   └──────────────► Repeat
```

## Future Improvements

* Display reaction time on a 16×2 LCD or OLED display.
* Store the fastest reaction time (high score).
* Add a buzzer for the start signal.
* Support multiple players.
* Calculate the average reaction time over several rounds.

---

## Author

**Swarnava Dey**
