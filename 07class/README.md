## آزمایش اول پیانو
## تجهیزات مورد نیاز:
* بلندگو(speaker)
* 4عدد پوش باتن (push button)
* برد بورد
* آردوینو uno
* سیم
  ## کد آزمایش:
#define T_C 262

#define T_D 294

#define T_A 440

#define T_B 493

const int D = 7;

const int C = 6;

const int A = 5;

const int B = 4;

const int Buzz = 11;

void setup()

{

  for ( int i = B; i <= D; i++)
  
   {
   
   pinMode(i, INPUT);
   
   digitalWrite(i, HIGH);
   
   }
   
}


void loop()

{

  while (digitalRead(D) == LOW)
  
   { tone(Buzz, T_D);}
  
  while (digitalRead(C) == LOW)
  
  {tone(Buzz, T_C);}
  
  while (digitalRead(A) == LOW)
  
  {tone(Buzz, T_A); }
  
   while (digitalRead(B) == LOW)

  { tone(Buzz, T_B);}
  
  noTone(Buzz);}
## آزمایش دوم راه اندازی سنسور دما LM35
## تجهیزات مورد نیاز:
* سنسور دما LM35
* برد بورد
* آردوینو uno
* سیم
  ## کد آزمایش:
  
#define sensorPin A0

void setup() 

{
  
  Serial.begin(9600);

}

void loop()

{
  
  int reading = analogRead(sensorPin);
 
  float voltage = reading * (5.0 / 1024.0);
  
  float temperatureC = voltage * 100;

  Serial.print("Temperature: ");
  
  Serial.print(temperatureC);
  
  Serial.print("\xC2\xB0"); 
  
  Serial.println("C  ,  ");

  delay(1000); 
}
## آزمایش سوم راه اندازی سنسور دما و رطوبت DHT11
## تجهیزات مورد نیاز:
* مقاومت
* سنسور دما و رطوبت DHT11
* برد بورد
* آردوینو uno
* سیم
  ## کد آزمایش:
 #include <Adafruit_Sensor.h>
 
#include "DHT.h"

#define DHTPIN 8   

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);
  
  dht.begin();

}

void loop() {

float h = dht.readHumidity();
  
float t = dht.readTemperature();


Serial.print(F("Humidity: "));

  Serial.print(h);
  
  Serial.print(F("%  Temperature: "));
  
  Serial.print(t);
  
  Serial.println(F("°C "));

  delay(1000);

}
## آزمایش چهارم استفاده از وقفه در آردوینو
## تجهیزات مورد نیاز:
* آردوینو uno
* سیم
*  ## کد آزمایش:
 volatile bool led_state = LOW;
 
 void setup()

{

  pinMode(13, OUTPUT); 
  
  pinMode(2, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING); 

}


void loop()

{

  digitalWrite(13, led_state); 

}

void blink() {

  led_state = !led_state; 
}
