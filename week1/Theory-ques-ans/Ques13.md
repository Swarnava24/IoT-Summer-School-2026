# Arduino Pin Types

The Arduino UNO offers several types of pins, each suited to a different kind of signal. Below is each type, what it does, the relevant pins on the UNO, and a real IoT use case.

## 1. Digital Input

Reads a signal that is either **HIGH (5V)** or **LOW (0V)** — used for sensors/switches that only have two states.

- **Pins:** D0–D13 (when configured with `pinMode(pin, INPUT)`)
- **Example:** Reading a push button or a PIR motion sensor's output
- **IoT use case:** A PIR motion sensor connected to a digital input pin detects movement in a smart home security system and triggers an alert.

## 2. Digital Output

Sends a signal that is either **HIGH (5V)** or **LOW (0V)** — used to turn things on/off.

- **Pins:** D0–D13 (when configured with `pinMode(pin, OUTPUT)`)
- **Example:** Turning an LED or relay on/off
- **IoT use case:** A digital output pin drives a relay module to switch a smart irrigation valve on or off remotely.

## 3. Analog Input

Reads a continuously variable voltage (0–5V) and converts it into a digital value (0–1023) using the onboard ADC.

- **Pins:** A0–A5
- **Example:** Reading a potentiometer or a temperature sensor (e.g. LM35)
- **IoT use case:** An LM35 temperature sensor connected to an analog input pin continuously reports temperature readings to a weather-monitoring IoT system.

## 4. PWM Output

Simulates an analog output by rapidly switching a digital pin HIGH/LOW at varying duty cycles — used to control brightness, speed, or position.

- **Pins:** D3, D5, D6, D9, D10, D11 (marked with a `~` on the UNO board)
- **Example:** Dimming an LED or controlling a DC motor's speed using `analogWrite()`
- **IoT use case:** A PWM pin controls a servo motor that adjusts the angle of a solar panel tracker to follow the sun throughout the day.

## 5. I2C / SPI Pins

Used for **communication between the Arduino and other digital devices/modules** (sensors, displays, memory chips) using a standardized protocol — fewer wires than connecting every signal individually.

- **I2C pins:** A4 (SDA – data), A5 (SCL – clock)
- **SPI pins:** D10 (SS), D11 (MOSI), D12 (MISO), D13 (SCK)
- **Example:** Connecting a 16x2 I2C LCD display or an SD card module (SPI)
- **IoT use case:** An I2C-based BMP280 sensor reports atmospheric pressure and altitude data to the Arduino, which forwards it to a cloud dashboard for a weather station project.

## Summary table

| Pin type | Pins on UNO | Signal | IoT use case |
|---|---|---|---|
| Digital Input | D0–D13 | HIGH/LOW | PIR motion sensor for security |
| Digital Output | D0–D13 | HIGH/LOW | Relay-controlled irrigation valve |
| Analog Input | A0–A5 | 0–1023 (from 0–5V) | LM35 temperature monitoring |
| PWM Output | D3,D5,D6,D9,D10,D11 | Variable duty cycle | Solar panel tracker servo |
| I2C / SPI | A4,A5 (I2C); D10–D13 (SPI) | Serial data protocol | BMP280 sensor to cloud dashboard |
