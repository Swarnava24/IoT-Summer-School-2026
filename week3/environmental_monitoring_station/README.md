# Environmental Monitoring Station

## Project Overview

The **Environmental Monitoring Station** is an Arduino-based system that monitors **temperature** and **humidity** using a **DHT22 sensor**. The measured temperature is displayed in both **Celsius (°C)** and **Fahrenheit (°F)**, while humidity is displayed as a percentage. The readings are transmitted to the Serial Monitor in **CSV (Comma-Separated Values)** format, making them easy to log or import into spreadsheet software. Two LEDs provide a quick visual indication of environmental conditions.

---

## Objectives

* Measure ambient temperature in Celsius and Fahrenheit.
* Measure relative humidity.
* Output sensor data in CSV format.
* Indicate normal and abnormal environmental conditions using LEDs.
* Demonstrate basic environmental monitoring using Arduino.

---

## Hardware Required

* Arduino Uno
* DHT22 Temperature & Humidity Sensor *(or DHT11 with minor code changes)*
* Green LED
* Red LED
* 2 × 220Ω Resistors
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

### LEDs

| LED       | Arduino Pin |
| --------- | ----------- |
| Red LED   | D8          |
| Green LED | D9          |

Connect each LED through a **220Ω resistor** to GND.

---

## Library Required

Install the following library using the Arduino Library Manager:

* **DHT Sensor Library** by Adafruit

---

## Working Principle

1. The Arduino reads:

   * Temperature in **Celsius (°C)**.
   * Temperature in **Fahrenheit (°F)**.
   * Relative humidity (%RH).
2. Sensor readings are printed to the Serial Monitor in CSV format:

```text id="d9n8qk"
timestamp,temp_C,temp_F,humidity
```

3. The system checks environmental conditions:

   * If **Temperature > 35°C** or **Humidity > 80%**, the **Red LED** turns ON.
   * Otherwise, the **Green LED** remains ON.
4. The monitoring process repeats every **2 seconds**.

---

## Features

* Temperature measurement in both Celsius and Fahrenheit.
* Relative humidity monitoring.
* CSV-formatted serial output for easy data logging.
* Visual status indication using LEDs.
* Automatic sensor error detection.
* Simple and efficient environmental monitoring.

---

## Environmental Thresholds

| Condition                             | LED Status   |
| ------------------------------------- | ------------ |
| Temperature ≤ 35°C and Humidity ≤ 80% | Green LED ON |
| Temperature > 35°C or Humidity > 80%  | Red LED ON   |

---

## How to Upload

1. Open the Arduino IDE.
2. Install the **DHT Sensor Library** by Adafruit.
3. Connect the Arduino Uno via USB.
4. Open the project sketch.
5. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
6. Click **Verify**.
7. Click **Upload**.
8. Open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

### CSV Output

```text id="zk9c8k"
timestamp,temp_C,temp_F,humidity
2000,27.5,81.5,58.0
4000,27.7,81.9,58.4
6000,28.0,82.4,59.1
```

### Sensor Error

```text id="6nl4bn"
Sensor Error
```

---

## Applications

* Weather monitoring stations
* Greenhouse environmental monitoring
* Smart home climate monitoring
* Industrial environmental monitoring
* Data logging and analysis
* IoT sensor node development

---

## Future Improvements

* Display readings on an LCD or OLED screen.
* Log sensor data to an SD card.
* Upload readings to cloud platforms using Wi-Fi.
* Add additional sensors such as air quality, pressure, or light sensors.
* Generate alerts when environmental conditions exceed safe limits.
* Integrate with mobile or web dashboards for remote monitoring.

---

## Author

**Swarnava Dey**
