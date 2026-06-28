int blinkCount = 0; //initialize a variable to count the number of blinks
int potentioPin = A0; //Potentiometer middle pin is connected to analog pin A0

void setup() {
  pinMode(13, OUTPUT); //led is connected to pin digital pin 13 and the pin is taken as output
  Serial.begin(9600); //starting the serial monitor with a fixed baud rate of 9600
}

void loop() {
  int delayTime = analogRead(potentioPin); //reading the value of potentiometer and storing it in delayTime variable

  digitalWrite(13, HIGH); //LED BECOMES ON
  delay(delayTime); //LED is on for delayTime value

  digitalWrite(13, LOW); //LED BECOMES OFF
  delay(delayTime); //LED is OFF for delayTime value

  blinkCount++; //updating counting by 1
  Serial.print("Blink count: "); //print the message
  Serial.println(blinkCount);
}
