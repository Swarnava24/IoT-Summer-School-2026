# DC Motor Speed Control using L298N

## Project Overview

The **DC Motor Speed Control** project demonstrates how to control the speed and direction of a DC motor using an **Arduino Uno**, an **L298N Motor Driver**, a **potentiometer**, and two **push buttons**. The potentiometer adjusts the motor speed using PWM, one button toggles the motor's direction (Forward/Reverse), and another button starts or stops the motor. The current motor direction, speed percentage, and running state are continuously displayed on the Serial Monitor.

---

## Objectives

* Control DC motor speed using PWM.
* Change motor direction using a push button.
* Start and stop the motor with another push button.
* Interface an Arduino with an L298N motor driver.
* Display motor status on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* L298N Motor Driver Module
* DC Motor
* Potentiometer (10kΩ)
* 2 × Push Buttons
* External Motor Power Supply (6–12V)
* Breadboard
* Jumper Wires

---

## Circuit Connections

### L298N Motor Driver

| L298N Pin | Arduino Pin           |
| --------- | --------------------- |
| ENA       | D9 (PWM)              |
| IN1       | D8                    |
| IN2       | D7                    |
| OUT1      | DC Motor Terminal 1   |
| OUT2      | DC Motor Terminal 2   |
| +12V      | External Motor Supply |
| GND       | Arduino GND           |

> **Important:** Connect the **Arduino GND** and the **motor power supply GND** together.

---

### Potentiometer

| Potentiometer Pin | Arduino Pin |
| ----------------- | ----------- |
| Left              | 5V          |
| Middle (Wiper)    | A0          |
| Right             | GND         |

---

### Push Buttons

| Button   | Function         | Arduino Pin |
| -------- | ---------------- | ----------- |
| Button 1 | Change Direction | D2          |
| Button 2 | Start/Stop Motor | D3          |

The sketch uses `INPUT_PULLUP`, so connect each button between the Arduino pin and **GND**.

---

## Working Principle

1. The potentiometer position is read using the Arduino's analog input.
2. The analog value (0–1023) is converted to a PWM value (0–255).
3. PWM is applied to the **ENA** pin of the L298N to control motor speed.
4. Pressing the **Direction** button toggles the motor between **Forward** and **Reverse** rotation.
5. Pressing the **Start/Stop** button enables or disables the motor.
6. Every 500 ms, the Serial Monitor displays:

   * Motor direction
   * Speed percentage
   * Running status

---

## Features

* PWM-based speed control.
* Forward and reverse motor rotation.
* Start/Stop functionality.
* Real-time motor status on the Serial Monitor.
* Debounced button inputs using simple delays.
* Compatible with the L298N motor driver.

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno via USB.
3. Open the project sketch.
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify** to compile the sketch.
6. Click **Upload**.
7. Open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

### Motor Running

```text id="78aq3k"
Direction: Forward | Speed: 75% | State: Running
Direction: Forward | Speed: 82% | State: Running
Direction: Reverse | Speed: 82% | State: Running
```

### Motor Stopped

```text id="3zj07l"
Direction: Reverse | Speed: 45% | State: Stopped
```

---

## Control Summary

| Input             | Action                       |
| ----------------- | ---------------------------- |
| Potentiometer     | Adjusts motor speed (0–100%) |
| Direction Button  | Toggles Forward/Reverse      |
| Start/Stop Button | Starts or stops the motor    |

---

## Applications

* Robotic vehicles
* Conveyor belt systems
* Automated manufacturing
* Smart home automation
* Industrial motor control
* Educational motor control experiments

---

## Future Improvements

* Replace delay-based button handling with `millis()` for non-blocking operation.
* Add an LCD or OLED to display motor speed and direction.
* Implement closed-loop speed control using an encoder.
* Add Bluetooth or Wi-Fi control for remote operation.
* Include overcurrent or overheating protection for the motor driver.
* Store the last motor settings in EEPROM.

---

## Author

**Swarnava Dey**

