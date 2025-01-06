## آزمایش اول نمایش اعداد واردشده در keypad در سریال مانیتور
## تجهیزات موردنیاز
* کی پد (keypad)
* برد آردوینو
* سیم
* سریال مانیتور نرم افزار آردوینو
  ## کد آزمایش
#include <key.h>  

#include <Keypad.h>

const byte ROWS = 4; 

char hexaKeys[ROWS][COLS] = {

  {'1', '2', '3', 'A'},

  {'4', '5', '6', 'B'},

  {'7', '8', '9', 'C'},

  {'*', '0', '#', 'D'}

};

byte colPins[ROWS] = {5, 4, 3, 2}; 

byte rowPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {

  Serial.begin(9600);

}

void loop() {

  char customKey = customKeypad.getKey();

  if (customKey) {

    Serial.println(customKey);

  }

}
## آزماش دوم ماشین حساب با keypad 
## تجهیزات موردنیاز
* کی پد (keypad)
* برد آردوینو
* سیم
* سریال مانیتور نرم افزار آردوینو
## کد آزمایش
#include <Key.h>

#include <Keypad.h>

const byte ROWS = 4; 

const byte COLS = 4; 

float firstNumber = 0;

float secondNumber = 0;

float result = 0;

bool section = false;

int type = 0;

char hexaKeys[ROWS][COLS] = {

  {'1', '2', '3', 'A'},

  {'4', '5', '6', 'B'},

  {'7', '8', '9', 'C'},

  {'*', '0', '#', 'D'}

};

byte colPins[ROWS] = {5, 4, 3, 2}; 

byte rowPins[COLS] = {9, 8, 7, 6}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {

  Serial.begin(9600); 

}

void loop() {

  int button = int(customKeypad.getKey()) - 48;

  if (0 <= button && button <= 10) {

    Serial.print(button);


    if (section == false) {

      firstNumber = firstNumber * 10 + button;

    } 
    
    else {

      secondNumber = secondNumber * 10 + button;
    
    }
  } 
   
  else {
  
    switch (button) {
  
      case 17://A
  
        section = true;
  
        type = 1;
  
        Serial.print('+');
  
        break;
  
      case 18://///B
  
        section = true;
  
        type = 2;
  
        Serial.print('-');
  
        break;
  
      case 19:////C

        section = true;

        type = 3;
        
        Serial.print('*');
        
        break;
     
      case 20:////D

        section = true;
     
        type = 4;
     
        Serial.print('/');
     
        break;
     
      case -6:////*

        section = false;
        
        type = 0;
        
        Serial.println(' ');
        
        break;
        
      case -13://///#
        
        Serial.print(" = ");
        
        switch (type) {
        
          case 1:
        
            result = (firstNumber + secondNumber);
        
            break;
        
          case 2:
        
            result = (firstNumber - secondNumber);
        
            break;
        
          case 3:
        
            result = (firstNumber * secondNumber);
        
            break;
        
          case 4:
        
            result = (firstNumber / secondNumber);
        
            break;
        
        }
        
        type = 0;
        
        Serial.println(result);
        
        firstNumber = 0;
        
        secondNumber = 0;
        
        section = false;
        
        break;

    }
  
  }

}
## آزمایش سوم کنترل led با وارد کردن پسورد در کی پد
## تجهیزات موردنیاز
* کی پد (keypad)
* برد آردوینو
* سیم
* led
* مقاومت 220اهم
* سریال مانیتور
## کد آزمایش
#include <Keypad.h>

const byte ROWS = 4;

const byte COLS = 4;

char keys[ROWS][COLS] = {

  {'1', '2', '3', 'A'},
  
  {'4', '5', '6', 'B'},
  
  {'7', '8', '9', 'C'},
  
  {'*', '0', '#', 'D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6};

byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String password = "1234";

String input = " ";

const int ledPin = 10;

void setup() {

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);

}

void loop() {

  char key = keypad.getKey();

  if (key) {

    Serial.print(key);

    if (key == '#') {

      if (input == password) {

        Serial.println("Password is ok :) ");

        digitalWrite(ledPin, HIGH);

      } else {

        Serial.println("Password is Wrong :( ");

        digitalWrite(ledPin, LOW);

      }

      input = "";

    } else if (key == '*') {

      input = "";

      Serial.println("Input cleared!");

    } else {

      input += key;

    }

  }

}
## آزمایش چهارم راه اندازی  joy stick
## تجهیزات موردنیاز
* جوی استیک (joy stick)
* برد آردوینو
* سیم
* برد بورد
* سریال مانیتور
## کد آزمایش
const int SW_pin = 8; 

const int X_pin = 0; 

const int Y_pin = 1;

void setup() {
 
  pinMode(SW_pin, INPUT);

  digitalWrite(SW_pin, HIGH);

  Serial.begin(9600);

}
 
void loop() {

  Serial.print("Switch:  ");

  Serial.print(digitalRead(SW_pin));

  Serial.print(" | ");

  Serial.print("X-axis: ");

  Serial.print(analogRead(X_pin));

  Serial.print(" | ");

  Serial.print("Y-axis: ");

  Serial.print(analogRead(Y_pin));

  Serial.println(" | ");

  delay(400);

}

## آزمایش پنجم کنترل شدت نور led با joy stick
## تجهیزات موردنیاز
* جوی استیک (joy stick)
* برد آردوینو
* led
* مقاومت
* سیم
* برد بورد
## کد آزمایش
const int ledpin =9; 

const int X_pin = 0; 

void setup() {

  pinMode(ledpin, OUTPUT);

 Serial.begin(9600);

}

void loop() {

  int xValue = analogRead(X_pin);

  int brightness = map( xValue,0,1023,0,255);

  analogWrite(ledpin,brightness);

 delay(100);

}

