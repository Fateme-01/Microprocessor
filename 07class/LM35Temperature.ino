
#define sensorPin A0

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1024.0);
  float temperatureC = voltage * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); 
  Serial.println("C  ,  ");



  delay(1000); 
}
