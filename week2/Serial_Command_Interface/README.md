# Serial Command Interface

## Project Overview

This project implements a **Serial Command Interface** using an Arduino Uno. Users can send text commands through the Arduino Serial Monitor to control the built-in LED, blink it a specified number of times, check the current system status, and reset the blink counter. The project demonstrates serial communication, command parsing, input validation, and basic hardware control.

---

## Objectives

* Learn serial communication between a computer and Arduino.
* Control hardware using text-based commands.
* Parse and validate user input.
* Maintain and display system status information.
* Handle invalid commands gracefully.

---

## Hardware Required

* Arduino Uno
* USB Cable
* Computer with Arduino IDE

**Note:** The project uses the Arduino's built-in LED (`LED_BUILTIN`), so no external LED or resistor is required.

---

## Hardware Connections

No external components are required.

| Component      | Arduino Pin                         |
| -------------- | ----------------------------------- |
| Built-in LED   | LED_BUILTIN (Pin 13 on Arduino Uno) |
| USB Connection | For Serial Communication            |

---

## Features

* Turn the built-in LED ON and OFF.
* Blink the LED 1–9 times using a serial command.
* Display the LED state and blink counter.
* Reset the blink counter.
* Input validation for unknown or invalid commands.

---

## Supported Commands

| Command   | Description                            |
| --------- | -------------------------------------- |
| `LED_ON`  | Turns the built-in LED ON              |
| `LED_OFF` | Turns the built-in LED OFF             |
| `BLINK_X` | Blinks the LED **X** times (`X` = 1–9) |
| `STATUS`  | Displays LED state and blink counter   |
| `RESET`   | Resets the blink counter to zero       |

---

## Example Serial Monitor Session

```text
=== Serial Command Interface ===
Available Commands:
LED_ON
LED_OFF
BLINK_X (X = 1-9)
STATUS
RESET

> LED_ON
LED is ON

> BLINK_5
Blinking 5 times

> STATUS
------ STATUS ------
LED State : OFF
Blink Counter : 5
--------------------

> RESET
Blink counter reset.

> STATUS
------ STATUS ------
LED State : OFF
Blink Counter : 0
--------------------

> ABC
ERROR: Unknown command
```

---

## How to Upload

1. Open the Arduino IDE.
2. Connect the Arduino Uno using a USB cable.
3. Open the project sketch.
4. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
5. Click **Verify** to compile the program.
6. Click **Upload**.
7. Open the **Serial Monitor**.
8. Set the baud rate to **9600** and choose **Newline** as the line ending.
9. Enter commands to control the LED.

---

## Expected Output

* `LED_ON` turns the built-in LED ON.
* `LED_OFF` turns the built-in LED OFF.
* `BLINK_X` blinks the LED the specified number of times.
* `STATUS` displays the LED state and total blink count.
* `RESET` clears the blink counter.
* Invalid commands display:


## Future Improvements

* Support multiple LEDs.
* Add PWM brightness control.
* Implement non-blocking blinking using `millis()`.
* Store settings in EEPROM.
* Add additional serial commands for controlling more peripherals.

---

## Author

**Swarnava Dey**
