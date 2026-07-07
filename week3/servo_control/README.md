# Servo Motor Control

## Project Overview

The **Servo Motor Control** project demonstrates how to control an **SG90 servo motor** using an **Arduino Uno**, a **potentiometer**, and a **push button**. The potentiometer allows smooth manual control of the servo angle from **0° to 180°**, while the push button initiates an automatic **full sweep (0° → 180° → 0°)**. The current servo angle is continuously displayed on the Serial Monitor.

---

## Objectives

* Control a servo motor using a potentiometer.
* Map analog input (0–1023) to servo angles (0°–180°).
* Perform an automatic servo sweep using a push button.
* Display the current servo angle on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* SG90 Servo Motor
* 10kΩ Potentiometer
* Push Button
* Breadboard
* Jumper Wires

---

## Circuit Connections

### SG90 Servo Motor

| Servo Wire             | Arduino Pin |
| ---------------------- | ----------- |
| Signal (Orange/Yellow) | D9          |
| VCC (Red)              | 5V          |
| GND (Brown/Black)      | GND         |

---

### Potentiometer

| Potentiometer Pin | Arduino Pin |
| ----------------- | ----------- |
| Left              | 5V          |
| Middle (Wiper)    | A0          |
| Right             | GND         |

---

### Push Button

| Button Pin     | Arduino Pin |
| -------------- | ----------- |
| One Terminal   | D2          |
| Other Terminal | GND         |

The sketch uses `INPUT_PULLUP`, so no external pull-up resistor is required.

---

## Library Required

Install the following library (included with the Arduino IDE):

* **Servo Library**

---

## Working Principle

1. The Arduino continuously reads the potentiometer value (0–1023).
2. The analog value is mapped to a servo angle between **0° and 180°**.
3. The servo motor rotates to the mapped angle.
4. The current angle is printed to the Serial Monitor every 100 ms.
5. When the push button is pressed:

   * The servo sweeps smoothly from **0° to 180°**.
   * It then returns from **180° back to 0°**.
6. After the sweep, manual potentiometer control resumes.

---

## Features

* Smooth manual servo angle control.
* Automatic full sweep using a push button.
* Real-time angle display on the Serial Monitor.
* Uses analog-to-angle mapping.
* Simple user interface with minimal components.

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno via USB.
3. Open the project sketch.
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify**.
6. Click **Upload**.
7. Open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

### Manual Control

```text
Servo Angle: 0
Servo Angle: 45
Servo Angle: 90
Servo Angle: 135
Servo Angle: 180
```

### Button Press

* Servo rotates from **0° → 180°**.
* Servo returns from **180° → 0°**.
* Manual potentiometer control resumes after the sweep.

---

## Applications

* Robotic arm control
* Camera pan and tilt systems
* Automated door and gate control
* RC vehicle steering
* Smart home automation
* Educational robotics projects

---

## Future Improvements

* Display the servo angle on an LCD or OLED screen.
* Add multiple preset positions selectable using buttons.
* Control the servo remotely using Bluetooth or Wi-Fi.
* Store the last servo position in EEPROM.
* Implement smoother motion using non-blocking timing (`millis()`).

---

## Author

**Swarnava Dey**
