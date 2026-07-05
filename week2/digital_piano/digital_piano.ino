/*
-------------------------------------------------------
Project: Digital Piano using Passive Buzzer
Author: Swarnava Dey
Date: 6-07-2026

Description:
- Four push buttons play musical notes.
- Pressing a button plays the assigned note.
- Releasing the button stops the sound.
- Pressing any two note buttons together plays
  Sol (392 Hz) as a chord substitute.
- A fifth button toggles between Major and Minor
  scales.
-------------------------------------------------------
*/

const int buzzer = 8;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int modeButton = 6;

// Major Scale
int majorScale[] = {262, 294, 330, 349};

// Minor Scale
int minorScale[] = {262, 294, 311, 349};

bool majorMode = true;
bool lastModeState = HIGH;

void setup() {

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(modeButton, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  Serial.println("Digital Piano");
  Serial.println("Mode: Major");
}

void loop() {

  // -------- Toggle Scale --------
  bool modeState = digitalRead(modeButton);

  if (lastModeState == HIGH && modeState == LOW) {

    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Mode: Major");
    else
      Serial.println("Mode: Minor");

    delay(200);
  }

  lastModeState = modeState;

  // -------- Read Buttons --------
  bool b1 = digitalRead(button1) == LOW;
  bool b2 = digitalRead(button2) == LOW;
  bool b3 = digitalRead(button3) == LOW;
  bool b4 = digitalRead(button4) == LOW;

  int pressed = b1 + b2 + b3 + b4;

  // Two or more buttons pressed
  if (pressed >= 2) {

    tone(buzzer, 392);

  }

  else if (b1) {

    tone(buzzer, majorMode ? majorScale[0] : minorScale[0]);

  }

  else if (b2) {

    tone(buzzer, majorMode ? majorScale[1] : minorScale[1]);

  }

  else if (b3) {

    tone(buzzer, majorMode ? majorScale[2] : minorScale[2]);

  }

  else if (b4) {

    tone(buzzer, majorMode ? majorScale[3] : minorScale[3]);

  }

  else {

    noTone(buzzer);

  }

}
