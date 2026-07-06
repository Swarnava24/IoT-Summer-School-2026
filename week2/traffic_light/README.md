# Traffic Light Controller

## Project Overview

The **Traffic Light Controller** simulates a basic road traffic signal system using an Arduino Uno and three LEDs representing **Red**, **Yellow**, and **Green** lights. The traffic lights operate in a fixed sequence with predefined timings. A pedestrian push button allows users to request an immediate stop, forcing the traffic light to switch to **Red** for 8 seconds to simulate a safe pedestrian crossing. The current traffic light state along with the system timestamp (`millis()`) is displayed on the Serial Monitor.

---

## Objectives

* Simulate a real-world traffic light controller.
* Control multiple LEDs with timed state transitions.
* Implement a pedestrian crossing request using a push button.
* Display system status with timestamps on the Serial Monitor.
* Demonstrate digital input/output and conditional logic.

---

## Hardware Required

* Arduino Uno
* 1 × Red LED
* 1 × Yellow LED
* 1 × Green LED
* 3 × 220Ω Resistors
* 1 × Push Button
* Breadboard
* Jumper Wires

> **Note:** The push button uses the Arduino's **internal pull-up resistor**, so no external resistor is required.

---

## Circuit Connections

### LEDs

| Component  | Arduino Pin |
| ---------- | ----------- |
| Red LED    | D8          |
| Yellow LED | D9          |
| Green LED  | D10         |

Connect each LED in series with a **220Ω resistor** to GND.

### Push Button

| Component   | Arduino Pin |
| ----------- | ----------- |
| Push Button | D7          |

Connect one side of the push button to **D7** and the other side to **GND**. The sketch uses `INPUT_PULLUP`, so the button reads **LOW** when pressed.

---

## Working Principle

1. The traffic light starts with the **Red LED ON** for **5 seconds**.
2. It changes to the **Yellow LED** for **2 seconds**.
3. It then changes to the **Green LED** for **4 seconds**.
4. During any state, the Arduino continuously checks for a pedestrian button press.
5. When a pedestrian request is detected, the controller immediately switches to the **Red LED**, holds it for **8 seconds**, and then restarts the traffic light sequence.
6. Every state change is printed on the Serial Monitor along with the current value of `millis()`.

---

## Features

* Automatic traffic light sequence.
* Pedestrian crossing request using a push button.
* Immediate transition to Red when requested.
* 8-second pedestrian crossing interval.
* Timestamped status updates using `millis()`.
* Uses Arduino's internal pull-up resistor for the button.

---

## Traffic Light Timing

| State                     |  Duration |
| ------------------------- | --------: |
| Red                       | 5 seconds |
| Yellow                    | 2 seconds |
| Green                     | 4 seconds |
| Pedestrian Crossing (Red) | 8 seconds |

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
7. Open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

### Traffic Light Sequence

* Red LED ON for **5 seconds**
* Yellow LED ON for **2 seconds**
* Green LED ON for **4 seconds**
* Sequence repeats continuously

### Pedestrian Mode

* Pressing the push button forces the signal to **Red**.
* Red remains ON for **8 seconds** before the normal sequence resumes.

### Serial Monitor Example

```text
Time: 0 ms | Light: RED
Time: 5000 ms | Light: YELLOW
Time: 7000 ms | Light: GREEN
Time: 9200 ms | Light: PEDESTRIAN CROSSING - RED
Time: 17200 ms | Light: RED
```

---

## Program Flow

```text
Start
   │
   ▼
RED (5 s)
   │
   ▼
Check Pedestrian Button
   │
   ├── Pressed → RED (8 s) → Restart
   │
   ▼
YELLOW (2 s)
   │
   ▼
Check Pedestrian Button
   │
   ├── Pressed → RED (8 s) → Restart
   │
   ▼
GREEN (4 s)
   │
   ▼
Check Pedestrian Button
   │
   ├── Pressed → RED (8 s) → Restart
   │
   ▼
Repeat
```

## Future Improvements

* Add a countdown timer using a 7-segment display or LCD.
* Implement separate vehicle and pedestrian traffic signals.
* Replace `delay()` with `millis()` for non-blocking operation.
* Add a buzzer for pedestrian crossing alerts.
* Include multiple traffic intersections with synchronized signals.

---

## Author

**Swarnava Dey**
