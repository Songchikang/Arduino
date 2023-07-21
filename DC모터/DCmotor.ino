//적외선 감지 센서를 이용해 DC모터 작동하는 소스입니다.
int infrared = A0;
int motor1 = 9;
int motor2 = 5;

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int state = analogRead(infrared);
  Serial.print("Infrared= ");  //측정된 센서값을 시리얼 모니터에 출력
  Serial.println(state);

  if(state < 100){
    digitalWrite(5,HIGH);
    digitalWrite(9,LOW);
    Serial.println("Warning");  //경보 메세지를 시리얼 모니터에 출력
  }
  else{
    digitalWrite(5,LOW);
    digitalWrite(9,LOW);
    Serial.println("Safe");  //안전 메세지를 시리얼 모니터에 출력
  }
}
