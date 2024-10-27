void setup() {
Serial.begin(9600);

}

void loop() {
int raw = analogRead(A0);
float voltage = raw * ( 5.0 / 1023.0 );

Serial.println("voltage:  ");
Serial.println(voltage);
delay(2000);

}
