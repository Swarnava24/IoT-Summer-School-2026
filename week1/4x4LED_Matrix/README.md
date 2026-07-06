# 4×4 LED Matrix Initials Display

## Project Overview

This project demonstrates how to control a **4×4 LED matrix** using an Arduino Uno through **row-column multiplexing**. The program displays the initials **"A"** and **"P"** alternately on the LED matrix. Multiplexing allows the entire matrix to be controlled using only **8 digital I/O pins**, making efficient use of the Arduino's GPIO pins.

---

## Objectives

* Learn the fundamentals of LED matrix multiplexing.
* Display custom character patterns on a 4×4 LED matrix.
* Alternate between two predefined characters ("A" and "P").
* Use only 8 Arduino digital pins for controlling all 16 LEDs.

---

## Hardware Required

* Arduino Uno
* 4×4 LED Matrix (or 16 individual LEDs arranged in matrix form)
* Breadboard
* Jumper wires
* 8 × 220 Ω resistors (recommended, one per row/column)

---

## Pin Connections

### Row Connections

| Matrix Row | Arduino Pin |
| ---------- | ----------- |
| Row 1      | D2          |
| Row 2      | D3          |
| Row 3      | D4          |
| Row 4      | D5          |

### Column Connections

| Matrix Column | Arduino Pin |
| ------------- | ----------- |
| Column 1      | D6          |
| Column 2      | D7          |
| Column 3      | D8          |
| Column 4      | D9          |

---

## Working Principle

The LED matrix is controlled using **multiplexing**.

Instead of powering all LEDs simultaneously, the Arduino rapidly scans each row one at a time while enabling the required columns for that row. Since this scanning occurs every few milliseconds, the human eye perceives all LEDs as being continuously lit due to persistence of vision.

The program stores each letter as a **4×4 boolean array**, where:

* `1` → LED ON
* `0` → LED OFF

Each character is displayed for **2 seconds** before switching to the next one.

---

## Character Patterns

### Letter A

```text
0100
1010
1110
1010
```

### Letter P

```text
1100
1010
1100
1000
```

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno using a USB cable.
3. Open the project (`led_matrix.ino`).
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify** to compile the sketch.
6. Click **Upload**.
7. Observe the LED matrix displaying the initials.

---

## Expected Output

* The LED matrix displays the letter **A** for approximately **2 seconds**.
* It then switches to the letter **P** for approximately **2 seconds**.
* The cycle repeats continuously.
* Characters appear stable due to rapid multiplexed scanning.

---

## Features

* 4×4 LED matrix control using multiplexing
* Displays custom character patterns
* Alternating display of initials
* Efficient use of only 8 Arduino digital pins
* Easy to modify for displaying other letters or symbols

---

## Future Improvements

* Display scrolling text.
* Add more alphabets and numbers.
* Control brightness using PWM.
* Display animations and simple icons.
* Interface with push buttons to change displayed characters.

---

## Author

**Swarnava Dey**

