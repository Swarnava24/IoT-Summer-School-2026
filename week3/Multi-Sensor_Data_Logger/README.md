# Multi-Sensor Data Logger

## Project Overview

The **Multi-Sensor Data Logger** is an Arduino-based environmental monitoring system that simultaneously reads data from three sensors:

* **DHT22 (Temperature and Humidity Sensor)**
* **LDR (Light Dependent Resistor)**
* **HC-SR04 Ultrasonic Sensor**

The system collects sensor readings every **5 seconds** and prints a structured log to the Serial Monitor. This project demonstrates how multiple sensors can be integrated into a single Arduino application for real-time environmental monitoring and data logging.

---

## Objectives

* Read multiple sensors simultaneously.
* Measure temperature and humidity using the DHT22 sensor.
* Measure ambient light intensity using an LDR.
* Measure distance using an HC-SR04 ultrasonic sensor.
* Display structured sensor logs every 5 seconds.

---

## Hardware Required

* Arduino Uno
* DHT22 Temperature & Humidity Sensor *(or DHT11 with minor code changes)*
* LDR (Light Dependent Resistor)
* 10kΩ Resistor (for LDR voltage divider)
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires

---

## Circuit Connections

### DHT22 Sensor

| DHT22 Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| DATA      | D2          |
| GND       | GND         |

---

### LDR

| Component                  | Arduino Pin |
| -------------------------- | ----------- |
| LDR Voltage Divider Output | A0          |
| LDR                        | 5V          |
| 10kΩ Resistor              | GND         |

---

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D9          |
| ECHO        | D10         |

---

## Library Required

Install the following library using the Arduino Library Manager:

* **DHT Sensor Library** by Adafruit

---

## Working Principle

1. Every **5 seconds**, the Arduino reads:

   * Temperature and humidity from the DHT22 sensor.
   * Raw light level from the LDR.
   * Distance using the HC-SR04 ultrasonic sensor.
2. The LDR value is converted into a percentage (0–100%) and classified as:

   * **Bright**
   * **Normal**
   * **Dark**
3. The ultrasonic sensor calculates distance using:

```text id="5grmyt"
Distance = (Duration × 0.034) / 2
```

4. All sensor readings are formatted and displayed on the Serial Monitor.

---

## Features

* Simultaneous monitoring of three sensors.
* Temperature and humidity measurement.
* Light intensity converted to percentage.
* Light condition classification.
* Distance measurement using ultrasonic sensing.
* Structured sensor log every 5 seconds.
* Simple and easy-to-read Serial Monitor output.

---

## How to Upload

1. Open the Arduino IDE.
2. Install the **DHT Sensor Library**.
3. Connect the Arduino Uno using a USB cable.
4. Open the project sketch.
5. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
6. Click **Verify**.
7. Click **Upload**.
8. Open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

```text id="zldvhy"
==================
SENSOR LOG
==================
Time      : 10000 ms
Temp      : 28.5 C | Humidity: 64.0%
Light     : 73% (Bright)
Distance  : 42.3 cm
==================
```

After another 5 seconds:

```text id="n0w9w7"
==================
SENSOR LOG
==================
Time      : 15000 ms
Temp      : 28.7 C | Humidity: 63.5%
Light     : 48% (Normal)
Distance  : 38.6 cm
==================
```

---

## Applications

* Environmental monitoring stations
* Smart home automation
* Weather monitoring systems
* Industrial condition monitoring
* IoT data acquisition systems
* Smart agriculture projects

---

## Future Improvements

* Save sensor logs to an SD card.
* Upload data to cloud platforms using Wi-Fi.
* Display readings on an LCD or OLED screen.
* Add a real-time clock (RTC) for actual timestamps.
* Trigger alarms based on sensor thresholds.
* Visualize sensor data using IoT dashboards.

---

## Author

**Swarnava Dey**
