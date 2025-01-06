## آزمابش اول نمایش کراکتر در lcd

## تجهیزات موردنیاز
* lcd
* پتانسیومتر
* برد آردوینو uno
* برد بورد
* سیم
## کد آزمایش
#include <LiquidCrystal.h>

LiquidCrystal Lcd(12,11,5,4,3,2);

void setup() {

  Lcd.begin(16, 2);

  Lcd.clear();

}

void loop() {

  Lcd.print("Hello world");
  
  Lcd.setCursor(0, 1);
  
  Lcd.print("lcd Tutorial");

}
## کد آزمایش
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte heart[8] = {

  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  
  lcd.begin(16, 2);
  
  lcd.createChar(0, heart);
  
  lcd.createChar(1, smiley);
  
  lcd.createChar(2, frownie);
  
  lcd.createChar(3, armsDown);
  
  lcd.createChar(4, armsUp);
  
  lcd.setCursor(0, 0);
  
  lcd.print("I ");
  
  lcd.write(byte(0)); 
  
  lcd.print(" Arduino! ");
  
  lcd.write((byte)1);

}
void loop() {
  
  int sensorReading = analogRead(A0);
  
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  
  lcd.setCursor(4, 1);
  
  lcd.write(3);
  
  delay(delayTime);
  
  lcd.setCursor(4, 1);
  
  lcd.write(4);
  
  delay(delayTime);

}
## کد آزمایش
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte armsDown[8] = {

  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  
  lcd.begin(16, 2);

  lcd.createChar(3, armsDown);
  
  lcd.createChar(4, armsUp);
  
  lcd.setCursor(0, 0);
  
  lcd.clear();

} 

void loop() {

  for(int i=0 ; i<16; i=i+2)
{
  lcd.setCursor(i, 0);

  lcd.write(3);
  
  delay(500);
  
  lcd.clear();
  
  lcd.setCursor(i+1, 0);
  
  lcd.write(4);
  
  delay(500);
  
  lcd.clear();

}

for(int j=16 ; j>=0; j=j-2)
{

  lcd.setCursor(j, 1);
  
  lcd.write(3);
  
  delay(500);
  
  lcd.clear();
  
  lcd.setCursor(j-1, 1);
  
  lcd.write(4);
  
  delay(500);
  
  lcd.clear();
}

}
