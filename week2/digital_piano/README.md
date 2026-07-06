# Digital Piano using Passive Buzzer

## Project Overview

This project implements a simple **4-key digital piano** using an Arduino Uno, four push buttons, and a passive buzzer. Each button plays a musical note when pressed, and the sound stops when the button is released. If two or more note buttons are pressed simultaneously, the piano plays **Sol (392 Hz)** as a chord substitute. A fifth push button allows the user to switch between **Major** and **Minor** scales.

---

## Objectives

* Generate musical notes using the Arduino `tone()` function.
* Read multiple push button inputs.
* Toggle between Major and Minor musical scales.
* Detect multiple simultaneous button presses.
* Demonstrate basic digital sound generation.

---

## Hardware Required

* Arduino Uno
* Passive Buzzer
* 5 Push Buttons
* Breadboard
* Jumper Wires
* 5 × 10kΩ Pull-down Resistors *(or use internal pull-up as implemented in the code)*

---

## Circuit Connections

### Passive Buzzer

| Component  | Arduino Pin |
| ---------- | ----------- |
| Buzzer (+) | D8          |
| Buzzer (−) | GND         |

### Push Buttons

| Button   | Function           | Arduino Pin |
| -------- | ------------------ | ----------- |
| Button 1 | Do                 | D2          |
| Button 2 | Re                 | D3          |
| Button 3 | Mi                 | D4          |
| Button 4 | Fa                 | D5          |
| Button 5 | Major/Minor Toggle | D6          |

**Note:** The sketch uses `INPUT_PULLUP`, so each button should connect between the Arduino pin and **GND**. No external pull-down resistors are required.

---

## Musical Notes

### Major Scale

| Note | Frequency |
| ---- | --------: |
| Do   |    262 Hz |
| Re   |    294 Hz |
| Mi   |    330 Hz |
| Fa   |    349 Hz |

### Minor Scale

| Note | Frequency |
| ---- | --------: |
| Do   |    262 Hz |
| Re   |    294 Hz |
| Mi♭  |    311 Hz |
| Fa   |    349 Hz |

### Chord Substitute

| Condition                        | Output       |
| -------------------------------- | ------------ |
| Two or more note buttons pressed | Sol (392 Hz) |

---

## Features

* Four playable musical notes.
* Sound stops automatically when the button is released.
* Chord substitute (Sol) for multiple simultaneous button presses.
* Toggle between Major and Minor scales.
* Displays the current scale on the Serial Monitor.

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno via USB.
3. Open the project sketch.
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify** to compile the program.
6. Click **Upload**.
7. Open the **Serial Monitor** at **9600 baud** to view the current scale.

---

## Expected Output

### Serial Monitor

```text
Digital Piano
Mode: Major
```

Pressing the mode button:

```text
Mode: Minor
```

Pressing it again:

```text
Mode: Major
```

### Piano Operation

| Action                     | Result                                  |
| -------------------------- | --------------------------------------- |
| Press Button 1             | Plays Do                                |
| Press Button 2             | Plays Re                                |
| Press Button 3             | Plays Mi (Major) / Mi♭ (Minor)          |
| Press Button 4             | Plays Fa                                |
| Release Button             | Sound stops                             |
| Press any two note buttons | Plays Sol (392 Hz)                      |
| Press Mode Button          | Switches between Major and Minor scales |

---

## Future Improvements

* Add an LCD or OLED display to show the current note and scale.
* Increase the number of keys to play a full octave.
* Implement volume control using PWM.
* Record and replay melodies.
* Add predefined songs and playback mode.

---

## Author

**Swarnava Dey**
