# Ultrasonic Parking Sensor

## Project Overview

The **Ultrasonic Parking Sensor** is an Arduino-based driver assistance system that uses an **HC-SR04 ultrasonic sensor** to measure the distance between a vehicle and nearby obstacles. Based on the measured distance, the system provides visual feedback using **Green, Yellow, and Red LEDs** and audible feedback using a **buzzer**. Four safety zones—**SAFE**, **WARNING**, **DANGER**, and **STOP**—help the driver park safely. The project uses the `millis()` function for non-blocking timing instead of `delay()`.

---

## Objectives

* Measure distance using the HC-SR04 ultrasonic sensor.
* Indicate parking safety using colored LEDs.
* Generate different buzzer alert patterns based on obstacle distance.
* Implement non-blocking timing using `millis()`.
* Display real-time distance and status on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Green LED
* Yellow LED
* Red LED
* Passive Buzzer
* 3 × 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Circuit Connections

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D9          |
| ECHO        | D10         |

---

### LEDs

| LED        | Arduino Pin |
| ---------- | ----------- |
| Green LED  | D2          |
| Yellow LED | D3          |
| Red LED    | D4          |

Connect each LED through a **220Ω resistor** to GND.

---

### Buzzer

| Component      | Arduino Pin |
| -------------- | ----------- |
| Passive Buzzer | D8          |

---

## Working Principle

1. The HC-SR04 sensor sends an ultrasonic pulse and measures the echo return time.
2. The distance is calculated using:

```text id="ecw6qb"
Distance = (Duration × 0.034) / 2
```

3. Based on the measured distance, the system enters one of four zones:

* **SAFE (> 50 cm):** Green LED remains ON.
* **WARNING (20–50 cm):** Yellow LED remains ON and the buzzer beeps slowly.
* **DANGER (10–20 cm):** Red LED remains ON and the buzzer beeps rapidly.
* **STOP (< 10 cm):** All LEDs flash together while the buzzer sounds continuously.

4. The current distance and parking status are printed to the Serial Monitor.

---

## Distance Zones

| Distance | Status  | LED            | Buzzer             |
| -------: | ------- | -------------- | ------------------ |
|  > 50 cm | SAFE    | Green          | OFF                |
| 20–50 cm | WARNING | Yellow         | Slow beep (500 ms) |
| 10–20 cm | DANGER  | Red            | Fast beep (200 ms) |
|  < 10 cm | STOP    | All LEDs Flash | Continuous tone    |

---

## Features

* Real-time obstacle distance measurement.
* Four parking safety levels.
* LED-based visual indication.
* Buzzer-based audible alerts.
* Non-blocking timing using `millis()`.
* Continuous Serial Monitor updates.

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

### Safe Distance

```text id="e3yuhq"
Distance: 82.5 cm
SAFE
```

### Warning Zone

```text id="wy3q97"
Distance: 36.8 cm
WARNING
```

### Danger Zone

```text id="6a5bxg"
Distance: 15.4 cm
DANGER
```

### Stop Zone

```text id="nln1hl"
Distance: 6.7 cm
STOP
```

---

## Applications

* Vehicle parking assistance systems
* Obstacle detection robots
* Smart garage parking systems
* Collision avoidance systems
* Automated guided vehicles (AGVs)
* Robotics and automation projects

---

## Future Improvements

* Display distance on an LCD or OLED screen.
* Add RGB LEDs for smoother status indication.
* Integrate with ESP32 for IoT-based parking monitoring.
* Send parking alerts to a mobile application via Bluetooth or Wi-Fi.
* Add voice alerts for different parking zones.
* Log parking data to an SD card or cloud platform.

---

## Author

**Swarnava Dey**
