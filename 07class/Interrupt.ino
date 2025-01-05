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
