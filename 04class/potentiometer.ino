int ledpin =9;
int analogPin = (A3);
int val=0;

void setup() {

pinMode(ledpin, OUTPUT);

}

void loop() {

val =analogRead(analogPin);
analogWrite(ledpin , val/4);

}
