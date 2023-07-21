int Button2 = 2;
int Button3 = 3;
int Button4 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int buttonState2 = digitalRead(2);
  Serial.println(buttonState2);
  delay(1);

  int buttonState3 = digitalRead(3);
  Serial.println(buttonState3);
  delay(1);

  int buttonState4 = digitalRead(4);
  Serial.println(buttonState4);
  delay(1);

  digitalWrite(8, buttonState2);
  digitalWrite(9, buttonState3);
  digitalWrite(10, buttonState4);
}
