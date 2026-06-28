# LED Blink Project

## Project Title

Arduino LED Blink with Serial Monitor and Potentiometer Control

---

## Project Description

This project demonstrates a basic Arduino LED blink program. The LED blink interval is initially set to 500 ms and is later controlled using a potentiometer. The sketch also displays the blink count on the Serial Monitor.

---

## Hardware Required

* Arduino Uno
* USB cable
* LED (or use the built-in LED on pin 13)
* 220 Ω resistor (if using an external LED)
* Potentiometer (10 kΩ)
* Breadboard
* Jumper wires

---

## Circuit Diagram Description

* Connect the LED anode to Digital Pin 13 through a 220 Ω resistor.
* Connect the LED cathode to GND.
* Connect one terminal of the potentiometer to 5V.
* Connect the other terminal to GND.
* Connect the middle (wiper) terminal of the potentiometer to Analog Pin A0.
* Connect the Arduino to the computer using the USB cable.

---

## How to Upload the Code

1. Connect the Arduino board to your computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` file.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM port from **Tools → Port**.
6. Click the **Verify** button to compile the code.
7. Click the **Upload** button to upload the program to the Arduino.
8. Open the Serial Monitor at **9600 baud** to view the blink count.

---

## Expected Output

* The LED blinks continuously.
* The blink speed changes when the potentiometer is rotated.
* The Serial Monitor displays:

  ```
  Blink count: 1
  Blink count: 2
  Blink count: 3
  ...
  ```

---

## Troubleshooting Tips

1. Ensure the correct Arduino board and COM port are selected in the Arduino IDE.
2. Verify all wiring connections, especially the LED and potentiometer connections.
3. Check that the Serial Monitor baud rate is set to **9600**.
4. If the LED does not blink, confirm that Pin 13 is correctly used or that the external LED polarity is correct.
5. Re-upload the sketch if compilation or upload fails.

---

## Author

**Swarnava Dey**
