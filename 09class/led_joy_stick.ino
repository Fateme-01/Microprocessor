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
