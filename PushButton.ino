const int but = 2;
const int led = 13;
int buttonstate = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  buttonstate = digitalRead(but);
  if (buttonstate == HIGH) {
    digitalWrite(led , HIGH);
  } else {
    digitalWrite(led , LOW);
  }
}

