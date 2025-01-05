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
