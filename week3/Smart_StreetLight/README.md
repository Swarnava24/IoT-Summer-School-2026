# Smart Street Light

## Project Overview

The **Smart Street Light** is an Arduino-based IoT project that automatically controls street lighting based on ambient light and motion detection. An **LDR (Light Dependent Resistor)** determines whether it is day or night, while a **PIR motion sensor** detects nearby movement. During the day, the street light remains OFF to conserve energy. At night, the LED glows at **20% brightness** when no motion is detected and switches to **100% brightness** for **30 seconds** whenever motion is sensed. All system events are logged to the Serial Monitor with timestamps.

---

## Objectives

* Automatically detect day and night using an LDR.
* Detect motion using a PIR sensor.
* Control LED brightness using PWM.
* Reduce power consumption through intelligent lighting.
* Log system events with timestamps.

---

## Hardware Required

* Arduino Uno
* LDR (Light Dependent Resistor)
* 10kΩ Resistor (for LDR voltage divider)
* PIR Motion Sensor (HC-SR501)
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires

---

## Circuit Connections

### LDR

| Component                  | Arduino Pin |
| -------------------------- | ----------- |
| LDR Voltage Divider Output | A0          |
| LDR                        | 5V          |
| 10kΩ Resistor              | GND         |

### PIR Motion Sensor

| PIR Pin | Arduino Pin |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| OUT     | D2          |

### LED

| Component   | Arduino Pin                 |
| ----------- | --------------------------- |
| LED Anode   | D9 (PWM)                    |
| LED Cathode | GND (through 220Ω resistor) |

---

## Working Principle

1. The Arduino continuously reads the LDR value.
2. If the light level is above the threshold, it is considered **daytime**, and the LED remains OFF.
3. If the light level falls below the threshold, the system enters **Night Mode**.
4. During Night Mode:

   * If motion is detected by the PIR sensor, the LED brightness increases to **100%**.
   * The LED remains at full brightness for **30 seconds** after the last detected motion.
   * If no motion is detected for 30 seconds, the LED brightness is reduced to **20%** using PWM.
5. Every important event is logged to the Serial Monitor with a timestamp in **HH:MM:SS** format.

---

## Features

* Automatic day/night detection using an LDR.
* Motion detection using a PIR sensor.
* PWM-controlled LED brightness.
* Full brightness for 30 seconds after motion detection.
* Energy-saving dim mode (20% brightness).
* Timestamped event logging on the Serial Monitor.

---

## System Behaviour

| Condition                | LED Brightness |
| ------------------------ | -------------: |
| Daylight                 |            OFF |
| Night + No Motion        |            20% |
| Night + Motion Detected  |           100% |
| No Motion for 30 Seconds | Returns to 20% |

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

### Daytime

```text
[00:00:05] EVENT: DAYLIGHT - LED OFF
```

### Night Mode

```text
[00:01:12] EVENT: Night Mode
```

### Motion Detected

```text
[00:01:18] EVENT: Motion Detected - LED FULL
```

### No Motion

```text
[00:01:48] EVENT: No Motion - LED DIM (20%)
```

## Applications

* Smart city street lighting
* Parking lot illumination
* Residential outdoor lighting
* Campus and pathway lighting
* Energy-efficient public infrastructure

---

## Future Improvements

* Replace the LED with a relay-controlled street lamp.
* Add Wi-Fi connectivity for remote monitoring.
* Store event logs in cloud storage.
* Integrate weather data to improve lighting decisions.
* Add solar power and battery management.
* Include multiple PIR sensors for wider coverage.

---

## Author

**Swarnava Dey**
