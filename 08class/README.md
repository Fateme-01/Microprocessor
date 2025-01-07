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
## توضیحات سخت افزاری

    پایه SDA (A4 برای Arduino Uno) و SCL (A5 برای Arduino Uno) دو برد را به یکدیگر متصل کنید.
    پایه GND دو برد را به یکدیگر متصل کنید.
    LED هر برد را به ترتیب به پین‌های 13 متصل کرده و طرف دیگر آن را به GND وصل کنید
    ## توضیحات کد
* کد Master:

        پین 13: LED برد Master.
        پین 2 و 3: برای اتصال I2C.
    وظایف Master:
        ارسال دستورات ("on" یا "off") به Slave.
        دریافت وضعیت Slave و کنترل LED خود.

* کد Slave:

        پین 13: LED برد Slave.
        پین 2 و 3: برای اتصال I2C.
    وظایف Slave:
        دریافت دستورات از Master و کنترل LED.
        ارسال وضعیت ("on" یا "off") به Master.
## نحوه اجرا
    هر کد را به برد مربوطه آپلود کنید:
        کد Master روی برد اول.
        کد Slave روی برد دوم.
    بردها را به یکدیگر متصل کنید.
    سریال مانیتور را برای برد Master باز کنید:
        دستور "on" یا "off" را وارد کنید تا وضعیت LED Slave تغییر کند.
        وضعیت Slave (روشن یا خاموش بودن LED) در سریال مانیتور Master نمایش داده می‌شود.
    سریال مانیتور را برای برد Slave باز کنید:
        می‌توانید دستورات را تغییر دهید و وضعیت جدید را به Master ارسال کنید.


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
