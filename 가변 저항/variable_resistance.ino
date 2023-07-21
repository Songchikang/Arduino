int val = 0;
int ledRed = 8;
int ledGreen = 9;
int ledBlue = 10;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if(val <= 350){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }
  else if(val > 350 && val <= 700){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }
  else {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
  delay(20);
}
