
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led , OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("sensor voltage=");
  Serial.println(sensorValue);
  delay(500);

  if (sensorValue > 800)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}
