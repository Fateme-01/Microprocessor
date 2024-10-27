int ledpin =9;
int analogPin = 0;
int val=5;

void setup() {

pinMode(ledpin, OUTPUT);

}

void loop() {

analogWrite(ledpin ,analogPin);
analogPin =analogPin +val;
if (analogPin <= 0 || analogPin >= 255)
{
  val = -val;
}
delay(10);

}
