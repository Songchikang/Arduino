#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,7,6,5,4);


void setup() {
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.write("202032030");
 lcd.setCursor(0,1);
 lcd.write("chikang");
}

void loop() {

}
