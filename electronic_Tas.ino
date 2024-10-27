long randomnumber;
const int but = A0;
const int pinLed[] = {0, 1 , 2 , 3 , 4 , 5};
#define key1 digitalRead(A0)
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(A0, INPUT);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}
void loop()
{
  int randnum = random(0 , 6);
  if (key1 == LOW)
  {
    digitalWrite ( pinLed[randnum] , HIGH);
    delay(2000);
    digitalWrite ( pinLed[randnum] , LOW);
    Serial.println(randnum + 1);
  }

}

