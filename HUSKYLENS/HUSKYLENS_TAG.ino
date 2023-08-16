#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;

void printResult(HUSKYLENSResult result);

void setup() {
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
    Serial.println("한라대");
    delay(3000);
  }
  else if (result.ID == 2){
    Serial.println("통신보안");
    delay(3000);
  }
  else if (result.ID == 3){
    Serial.println("7사단");
    delay(3000);
  }
  else{
    Serial.println("아무것도 없음");
    delay(3000);
  }
}
