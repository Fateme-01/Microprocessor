## آزمایش اول اتصال ماژول مادون قرمز IR(infrared) و led
## تجهیزات موردنیاز
* ماژول مادون قرمز IRگیرنده
* led
* مقاومت 220اهم
* برد بورد
* بورد آردوینو uno
##  کد آزمایش
int ir = 2;

int PinLed = 10;

int val=0;
  
void setup()
{
 
    pinMode(ir, INPUT);
 
    pinMode(PinLed, OUTPUT);
 
}
 
void loop()
{
 
    if(digitalRead(ir) == LOW)
 
    {

        digitalWrite(PinLed, HIGH);

    }

    else

    {

        digitalWrite(PinLed, LOW);

    }

}
## آزمایش دوم کنترل ماژول بلوتوث با اپلیکیشن terminal bt
## تجهیزات موردنیاز
* ماژول بلوتوث
* اپلیکیشن terminal bt
* led
* مقاومت 220اهم
* بردبورد
* برد آردوینو  uno
* سیم
## کد آزمایش
#include <SoftwareSerial.h>

SoftwareSerial BTserial(2,3);

#define ledPin 7

int state = 0;

void setup() {

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);

Serial.begin(9600);

  BTserial.begin(9600); 
  
}

void loop() {

  if(BTserial.available() > 0){ 

    state = BTserial.read(); 

 }

 if (state == '0') {

  digitalWrite(ledPin, LOW); 

  Serial.println("LED: OFF"); 

  state = 1;

 }

 else if (state == '1') {

  digitalWrite(ledPin, HIGH);

  Serial.println("LED: ON");

  state = 0;

 } 

}
