//버튼을 이용해 DC모터 작동하는 소스입니다.
const int motor1 = 5;
const int motor2 = 4;
const int button1 = 3;
const int button2 = 2;
boolean buttonState1 = false;
boolean buttonState2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  int forward = digitalRead(3);
  int backward = digitalRead(2);

  if(forward == LOW){
    if(backward == LOW){
      analogWrite(4,0);
      analogWrite(5,0);
    }
    else if(backward == HIGH){
      analogWrite(4,255);
      analogWrite(5,0);
    }
  }
  else if(forward == HIGH){
    if(backward == LOW){
      analogWrite(4,0);
      analogWrite(5,255);
    }
    else if(backward == HIGH){
      analogWrite(4,0);
      analogWrite(5,0);
    }
  }
  Serial.print("forward: ");
  Serial.print(forward);
  Serial.print("|     backward: ");
  Serial.println(backward);
  delay(500);
}
