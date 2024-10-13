int led = 13;
int LED = 12;
void setup() {
 pinMode (led, OUTPUT);
 pinMode (LED, OUTPUT);

}

void loop() {
digitalWrite (led, HIGH);
delay (1000);
digitalWrite (LED, LOW);
delay (1000);

}
