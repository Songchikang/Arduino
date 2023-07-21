void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  analogWrite(8, 227);
  analogWrite(9, 0);
  analogWrite(10, 255);
  delay(1000);

  analogWrite(8, 0);
  analogWrite(9, 255);
  analogWrite(10, 255);
  delay(1000);

  analogWrite(8, 255);
  analogWrite(9, 255);
  analogWrite(10, 255);
  delay(1000);
}
