/*
-------------------------------------------------------
Project: 4x4 LED Matrix Initials Display
Author: Swarnava Dey
Date: 6-07-2026

Description:
- Controls a 4x4 LED matrix using row-column multiplexing.
- Displays the initials "A" and "P" alternately.
- Each character is shown for 2 seconds before switching.
- Uses only 8 Arduino digital pins (4 rows and 4 columns).
- Implements matrix scanning for continuous LED display.
-------------------------------------------------------
*/

const int rows[4] = {2, 3, 4, 5};
const int cols[4] = {6, 7, 8, 9};

// Pattern to display (1 = LED ON)
bool pattern[4][4] = {
  {0,1,0,0},
  {1,0,1,0},
  {1,1,1,0},
  {1,0,1,0}
};

void setup() {
  for(int i=0;i<4;i++){
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);

    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}

void scanMatrix(bool p[4][4])
{
  for(int r=0;r<4;r++)
  {
    // Turn everything off
    for(int i=0;i<4;i++)
    {
      digitalWrite(rows[i], LOW);
      digitalWrite(cols[i], HIGH);
    }

    // Enable one row
    digitalWrite(rows[r], HIGH);

    // Turn on LEDs in that row
    for(int c=0;c<4;c++)
    {
      if(p[r][c])
        digitalWrite(cols[c], LOW);
    }

    delay(2);   // Multiplex delay
  }
}

void loop()
{
  // Display "A"
  bool A[4][4]={
    {0,1,0,0},
    {1,0,1,0},
    {1,1,1,0},
    {1,0,1,0}
  };

  unsigned long t = millis();

  while(millis()-t < 2000)
    scanMatrix(A);

  t = millis();

  while(millis()-t < 2000)
    scanMatrix(P);
}
