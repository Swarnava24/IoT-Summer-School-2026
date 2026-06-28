# setup() and loop() Functions

## setup()
Runs **once** when the Arduino powers on or resets. Used for one-time initialization — setting pin modes, starting Serial communication, initializing sensors/libraries.

## loop()
Runs **repeatedly, forever**, right after `setup()` finishes. This is where the main program logic lives — reading sensors, updating outputs, checking conditions — over and over.

## Effect of a long delay() inside loop()
`delay(ms)` **completely pauses** the entire program for that duration — no other code runs, no pins are read, no buttons are checked. If you put, say, `delay(5000)` inside `loop()`, the Arduino becomes unresponsive for those 5 seconds: it can't react to a button press, can't take a new sensor reading, and can't update any output in that time.

## Effect on sensor reading responsiveness
This makes the system **laggy and unreliable** for real-time tasks. Fast-changing inputs (e.g. a button press, an incoming signal) get missed or delayed if they occur during the `delay()`. Sensors only get read once per delay cycle instead of continuously, so the data is stale and the system can't respond quickly to changes.

## Non-blocking alternative
Use **`millis()`** instead of `delay()`. `millis()` returns the number of milliseconds since the program started, without pausing anything. By comparing the current `millis()` value to a stored "last action time," you can check *"has enough time passed?"* on every loop pass — while still reading sensors and checking inputs continuously in the background.

```cpp
unsigned long lastTime = 0;
const long interval = 5000;

void loop() {
  // sensors/buttons are still checked every loop, no blocking
  if (millis() - lastTime >= interval) {
    lastTime = millis();
    // do the timed action here
  }
}
```

This keeps the Arduino responsive to all inputs at all times, instead of freezing during a wait.
