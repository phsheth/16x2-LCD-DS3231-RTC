

// Include LCD Library Code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// Include the DS3231 RTC Library
#include  <DS3231.h>


LiquidCrystal_I2C lcd(0x27,16,2);
//initialize the DS3231 rtc
DS3231  rtc(SDA, SCL);
Time  t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Wire.begin();
  rtc.begin();
  lcd.init();

  
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pushkar Sheth");  
      lcd.setCursor(0,1);
      t = rtc.getTime();
lcd.print(t.hour);
lcd.print(":");
lcd.print(t.min);
lcd.print(":");
lcd.print(t.sec);
delay(1000);
}
