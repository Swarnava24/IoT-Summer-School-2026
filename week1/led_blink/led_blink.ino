void setup() {
  pinMode(13, OUTPUT); //led anode leg is connected to digital pin 13 as output
}

void loop() {
  digitalWrite(13, HIGH);  //LED IS ON
  delay(500); //500ms delay
  digitalWrite(13, LOW); //LED IS OFF
  delay(500); //500ms delay
}
