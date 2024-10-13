int led = 13;
int LED = 12;
void setup() {
 pinMode (led, OUTPUT);
 pinMode (LED, OUTPUT);

}

void loop() {
digitalWrite (led, HIGH);
delay (5000);
digitalWrite (led, LOW);
delay (500);
digitalWrite (LED, HIGH);
delay (5000);
digitalWrite (LED, LOW);
delay (500);

}
