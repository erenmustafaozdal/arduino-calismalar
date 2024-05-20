#include <LiquidCrystal.h>
#include <virtuabotixRTC.h>

int CLK_PIN = 11;
int DAT_PIN = 12;
int RST_PIN = 13;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Dijital LCD kontrast ayarı
int cs=9;// Kontrast PWM için pin 9
const int contrast = 100;// Varsayılan kontrast

int bl=10; // Backlight pin
const int backlight=120; // no more then 7mA !!!

void setup() {
  lcd.begin(16, 2);
  myRTC.setDS1302Time(0, 54, 19, 1, 20, 5, 2024);
  analogWrite(cs,contrast);// Adjust Contrast VO
  analogWrite(bl,backlight);// Turn on Backlight
}

void loop() {
  myRTC.updateTime();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  
  lcd.setCursor(0, 1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.println(myRTC.seconds);
  delay(1000);
}