int blinkCount = 0; //initialize a variable to count the number of blinks

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); //this mkes a bridge between our laptop and arduino to communicate with a fixed baud rate of 9600
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(500);

  blinkCount++; //update the blinkCount value by 1
  Serial.print("Blink count: "); //print the message blink count on serial monitor
  Serial.println(blinkCount); //print the count value and then adds a newline character
}
