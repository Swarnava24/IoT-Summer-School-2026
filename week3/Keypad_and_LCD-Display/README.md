# Password Protected Access System

## Project Overview

The **Password Protected Access System** is an Arduino-based security project that uses a **4×4 membrane keypad** and a **16×2 LCD** to authenticate users. A user enters a **4-digit PIN**, which is masked with asterisks (`*`) on the LCD. If the entered PIN matches the stored password, access is granted and a **Green LED** lights up. If the PIN is incorrect, a **Red LED** and **buzzer** provide feedback. After **three consecutive incorrect attempts**, the system locks for **10 seconds** before allowing another attempt.

---

## Objectives

* Implement password-based access control.
* Read user input using a 4×4 keypad.
* Display messages on a 16×2 LCD.
* Provide visual and audio feedback.
* Implement a security lockout after multiple failed attempts.

---

## Hardware Required

* Arduino Uno
* 4×4 Membrane Keypad
* 16×2 LCD Display
* Green LED
* Red LED
* Passive/Active Buzzer
* 2 × 220Ω Resistors (for LEDs)
* Breadboard
* Jumper Wires

---

## Circuit Connections

### LCD (16×2)

| LCD Pin | Arduino Pin |
| ------- | ----------- |
| RS      | D12         |
| EN      | D11         |
| D4      | D5          |
| D5      | D4          |
| D6      | D3          |
| D7      | D2          |

### Keypad

| Keypad Pin | Arduino Pin |
| ---------- | ----------- |
| R1         | A0          |
| R2         | A1          |
| R3         | A2          |
| R4         | A3          |
| C1         | A4          |
| C2         | A5          |
| C3         | D6          |
| C4         | D7          |

### LEDs

| LED       | Arduino Pin |
| --------- | ----------- |
| Green LED | D8          |
| Red LED   | D9          |

Each LED should be connected through a **220Ω resistor** to GND.

### Buzzer

| Component | Arduino Pin |
| --------- | ----------- |
| Buzzer    | D10         |

---

## Working Principle

1. The LCD displays **"ENTER PIN:"**.
2. The user enters a **4-digit PIN** using the keypad.
3. Each digit is masked with an asterisk (`*`) on the LCD.
4. When four digits are entered:

   * If the PIN matches the stored password (`1234`), access is granted.
   * The Green LED lights for 3 seconds.
5. If the PIN is incorrect:

   * "ACCESS DENIED" is displayed.
   * The Red LED turns ON.
   * The buzzer sounds.
6. After **three incorrect attempts**, the system displays **"LOCKED 10 SECONDS"** and disables access for 10 seconds.
7. The system then resets and prompts the user to enter the PIN again.

---

## Features

* 4-digit password authentication.
* Password masking using `*`.
* LCD-based user interface.
* Green LED for successful authentication.
* Red LED and buzzer for failed authentication.
* Automatic lockout after three incorrect attempts.
* Reset of failed-attempt counter after successful login or lockout.

---

## Default Password

```text
1234
```

You can change the password by modifying:

```cpp
String password = "1234";
```

---

## How to Upload

1. Open the Arduino IDE.
2. Install the required libraries:

   * **Keypad**
   * **LiquidCrystal**
3. Connect the Arduino Uno using a USB cable.
4. Open the project sketch.
5. Select:

   * **Board:** Arduino Uno
   * **Port:** Appropriate COM port
6. Click **Verify**.
7. Click **Upload**.

---

## Expected Output

### LCD on Startup

```text
ENTER PIN:
```

### Correct Password

```text
ACCESS
GRANTED
```

* Green LED turns ON for 3 seconds.

---

### Incorrect Password

```text
ACCESS
DENIED
```

* Red LED turns ON.
* Buzzer sounds.

---

### Three Incorrect Attempts

```text
LOCKED
10 SECONDS
```

The keypad is disabled for 10 seconds before allowing new PIN entries.

---

## Applications

* Door access control systems
* Electronic lockers
* Security authentication systems
* Attendance terminals
* Smart home entry systems

---

## Future Improvements

* Store passwords securely in EEPROM.
* Allow users to change the password.
* Add RFID or fingerprint authentication.
* Display remaining login attempts.
* Integrate with IoT platforms for remote access logging.
* Add a servo motor or electronic lock for physical door control.

---

## Author

**Swarnava Dey**
