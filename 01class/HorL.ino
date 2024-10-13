const int led = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(led , OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0 )
{
  String incomingByte = Serial.readString ();
  if (incomingByte == "h")
  {
    digitalWrite(led , HIGH);
    }
    else if(incomingByte == "l" )
    {
      digitalWrite(led , LOW);
      }
  }
}
