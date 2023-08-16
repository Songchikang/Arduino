#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;

void printResult(HUSKYLENSResult result);

int red = 5;
int yellow = 6;
int green = 8;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  while (!huskylens.begin(Wire)){
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
    Serial.println(F("2.please recheck the connection"));
    delay(100);
  }
}

void loop() {
  if (!huskylens.request()){
    Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
  }
  else if (!huskylens.isLearned()){
    Serial.println(F("Nothing learned, press learn button on HUSKTLENS to learn one!"));
  }
  else if (!huskylens.available()){
    Serial.println(F("No block or arrow appears on the screen!"));
  }
  else {
    Serial.println(F("###########"));
    while (huskylens.available()){
      HUSKYLENSResult result = huskylens.read();
      printResult(result);
    }
  }
}

void printResult(HUSKYLENSResult result){
  if (result.ID == 1){
    digitalWrite(red, HIGH);
    delay(1000);
  }
  if (result.ID == 2){
    digitalWrite(yellow, HIGH);
    delay(1000);
  }
  if (result.ID == 3){
    digitalWrite(green, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
}
