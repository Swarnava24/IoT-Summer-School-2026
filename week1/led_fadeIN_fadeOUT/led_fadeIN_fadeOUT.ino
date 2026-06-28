/*
Author: Swarnava Dey
Date: 28-06-2026
Description: Arduino LED FADE IN, FADE OUT project using PWM pins of arduino.
*/


int ledPins[] = {3, 5, 6, 9, 10, 11}; //we are using PWM(Pulse Width Modulation) pins                   

void setup() {
  for (int i = 0; i<6; i++) { //we are traversing the ledPins array
    pinMode(ledPins[i], OUTPUT); //assigning all pins to output        
  }
}

void loop() {
  for (int i = 0; i < 6; i++) { 

    // FADE IN
    for (int bright = 0; bright <= 255; bright++) {
      analogWrite(ledPins[i], bright);
      delay(3);
    }

    // FADE OUT
    for (int bright = 255; bright >= 0; bright--) {
      analogWrite(ledPins[i], bright);
      delay(3);
    }

  }
}
