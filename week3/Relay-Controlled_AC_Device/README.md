# Relay-Controlled AC Device Simulation

## Project Overview

The **Relay-Controlled AC Device Simulation** demonstrates an automatic temperature-based control system using an **Arduino Uno**, a **DHT22 (or DHT11) temperature sensor**, and a **relay module** (simulated using an LED). The relay turns ON when the temperature rises above **32°C** and turns OFF when it falls below **28°C**. A **manual override button** allows the user to toggle the relay regardless of the temperature. All relay state changes, along with the current temperature, are logged to the Serial Monitor.

---

## Objectives

* Monitor ambient temperature using a DHT22/DHT11 sensor.
* Automatically control a relay based on temperature thresholds.
* Implement hysteresis to prevent rapid relay switching.
* Provide a manual relay override using a push button.
* Log all relay state changes with temperature readings.

---

## Hardware Required

* Arduino Uno
* DHT22 Temperature & Humidity Sensor *(or DHT11 with minor code changes)*
* Relay Module *(or LED for simulation)*
* Push Button
* 220Ω Resistor (for LED simulation)
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

### Relay / LED

| Component            | Arduino Pin |
| -------------------- | ----------- |
| Relay IN / LED Anode | D8          |
| Relay VCC            | 5V          |
| Relay GND            | GND         |

> **Note:** When simulating in Tinkercad, replace the relay with an LED connected through a **220Ω resistor**.

---

### Push Button

| Button Pin     | Arduino Pin |
| -------------- | ----------- |
| One Terminal   | D3          |
| Other Terminal | GND         |

The sketch uses `INPUT_PULLUP`, so no external pull-up resistor is required.

---

## Working Principle

1. The Arduino reads the temperature from the DHT sensor every second.
2. If the temperature exceeds **32°C**, the relay turns **ON** (simulating the AC turning ON).
3. The relay remains ON until the temperature drops below **28°C**.
4. The difference between the ON and OFF thresholds creates **hysteresis**, preventing rapid relay switching near the threshold.
5. Pressing the manual override button toggles the relay regardless of the current temperature.
6. Every relay state change is printed to the Serial Monitor along with the current temperature.

---

## Features

* Automatic temperature-based relay control.
* Hysteresis to prevent relay chatter.
* Manual relay override using a push button.
* Serial Monitor logging of relay events.
* Compatible with both relay modules and LED simulations.
* Suitable for Tinkercad and physical Arduino implementations.

---

## Temperature Thresholds

| Temperature           | Relay State             |
| --------------------- | ----------------------- |
| Above **32°C**        | Relay ON (AC ON)        |
| Between **28°C–32°C** | Maintain previous state |
| Below **28°C**        | Relay OFF (AC OFF)      |

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

### Automatic Relay ON

```text id="e5uwgq"
Temperature: 33.4 °C | Relay ON (AC ON)
```

### Automatic Relay OFF

```text id="qm31m7"
Temperature: 27.6 °C | Relay OFF (AC OFF)
```

### Manual Override

```text id="z8mwhd"
Temperature: 30.8 °C | Manual Override -> Relay ON
Temperature: 30.8 °C | Manual Override -> Relay OFF
```

---

## Applications

* Smart air conditioning systems
* Temperature-controlled appliances
* Industrial cooling systems
* Smart home automation
* Server room temperature monitoring
* Energy-efficient climate control

---

## Future Improvements

* Display temperature and relay status on an LCD or OLED.
* Add Wi-Fi or Bluetooth connectivity for remote monitoring.
* Log temperature data to an SD card or cloud platform.
* Replace the simulated relay with an actual AC-rated relay module.
* Implement adjustable temperature thresholds through buttons or a web interface.
* Add email or mobile notifications for high-temperature alerts.

---

## Author

**Swarnava Dey**
