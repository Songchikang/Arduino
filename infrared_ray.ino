//적외선 장애물 감지 센서는 적외선을 이용해서 앞에 장애물이 있는지 확인하는 센서입니다.
int infrared = A0;
int led = 6;
int Buzzer = 12;

void setup(){
  pinMode(infrared, INPUT);
  pinMode(led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);  //적외선 장애물 감지 센서의 상태를 확인하기 위하여 시리얼 통신의 속도를 설정
}

void loop(){
  int state = analogRead(infrared);
  Serial.print("Infrared= ");  //측정된 센서값을 시리얼 모니터에 출력
  Serial.println(state);

  if(state < 100){
    tone(12, 2093);      // buzzer 소리 남
    delay(10);
    tone(12, 523);
    delay(10);
    digitalWrite(led, HIGH);   //LED 킴
    Serial.println("Warning");  //경보 메세지를 시리얼 모니터에 출력
  }
  else{
    noTone(12);      // buzzer 소리 안남
    digitalWrite(led, LOW);  //LED 끔
    Serial.println("Safe");  //안전 메세지를 시리얼 모니터에 출력
  }
}
