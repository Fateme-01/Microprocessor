## آزمایش اول master and slave
## تجهیزات مورد نیاز
* دو عدد پتانسیومتر
* دوعدد led
* دو مقاومت 330 اهم
  * سیم
  * برد بورد
  * برد آردوینوuno
    ## کد آزمایش قسمت master
 #include <Wire.h>

int value = 0;

void setup() {

  Wire.begin(); 
  
  Serial.begin(9600);

  pinMode(5, OUTPUT);

}

void loop() {

  int y = analogRead(A1);         
  
  value = map(y, 0, 1023, 0, 255);

  Wire.beginTransmission(8); 
  
  Wire.write("Master value :  ");         
  
  Wire.write(value);              
  
  Wire.endTransmission();   
  
  Wire.requestFrom(8, 1);    
  
  while (Wire.available()) { 
  
    int c = Wire.read(); 

    analogWrite(5, c);

    Serial.print("Slave value : ");
    
    Serial.println(c);        
  
  }

  delay(100);

}
## کد آزمایش قسمت slave
#include <Wire.h>
int x;
int value = 0;

void setup() {

  Wire.begin(8);
  
  Wire.onRequest(requestEvent);
  
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
  
  pinMode(9, OUTPUT);

}

void loop() {

  delay(100);
  
  analogWrite(9, x);
  
  int t = analogRead(A0);
  
  value = map(t, 0, 1023, 0, 255);

}

void receiveEvent()

{

  while (1 < Wire.available()) 
  
  {
  
    char c = Wire.read();
    
    Serial.print(c);
    
  }
  
  x = Wire.read();
  
  Serial.println(x);
  
}

void requestEvent() 

{
  
  Wire.write(value);
  
  }
## آزمایش سوم driver motor
## تجهیزات مورد نیاز
* driver motor
* منبع تغذیه
  * سیم
  * برد آردوینوuno
    ## کد آزمایش
    void setup()
     {
    
  pinMode(9, OUTPUT);

  pinMode(8, OUTPUT);

  pinMode(10, OUTPUT);

}

void loop() {

  digitalWrite(9, HIGH);
  
  digitalWrite(8, LOW);
  
  digitalWrite(10, HIGH);
  
  delay(1000);
  
  digitalWrite(9, LOW);
  
  digitalWrite(8, HIGH);
  
  digitalWrite(10, HIGH);
  
  delay(1000);
  
  for (int i = 0; i < 256; i++)
  
  {
  
    digitalWrite(9, HIGH);
    
    digitalWrite(8, LOW);
    
    digitalWrite(10, i);
    
    delay(20);
  
  }
  
  delay(50);
  
  for (int i = 0; i < 256; i++)
  
  {
  
    digitalWrite(9, LOW);
    
    digitalWrite(8, HIGH);
    
    digitalWrite(10, i);
    
    delay(20);
 
  }
  
  delay(50);

}
