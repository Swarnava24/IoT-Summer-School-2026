# analogWrite() vs analogRead() and PWM

## analogRead()
Reads a varying voltage (0–5V) from an **analog input pin** (A0–A5) and converts it into a digital value between **0 and 1023** using the Arduino's built-in ADC (Analog-to-Digital Converter). It is used to take readings *from* sensors.

**IoT example:** Reading a soil moisture sensor's output on `A0` to monitor soil conditions for a smart irrigation system.

## analogWrite()
Outputs a simulated analog voltage on a **PWM-capable digital pin** by rapidly switching it HIGH/LOW at a given duty cycle, using a value between **0 (always off) and 255 (always on)**. It is used to control *output* devices with varying intensity.

**IoT example:** Controlling the brightness of an LED strip in a smart lighting system based on ambient light levels.

## What is PWM and why is it used?
**PWM (Pulse Width Modulation)** is a technique where a digital pin is switched ON and OFF very rapidly, and the *proportion of time it stays ON* (the duty cycle) determines the effective average voltage delivered. It's used because the Arduino can only output digital HIGH/LOW signals natively — PWM lets it **simulate analog-like control** (e.g., variable brightness or speed) without needing a true analog output circuit.

## Quick comparison

| | analogRead() | analogWrite() |
|---|---|---|
| Direction | Input (reads sensor) | Output (controls device) |
| Pins | A0–A5 | PWM pins (marked `~`, e.g. 3, 5, 6, 9, 10, 11) |
| Value range | 0–1023 | 0–255 |
| Purpose | Measure a varying voltage | Simulate a varying voltage |
