
void setup() {

Serial.begin(9600);

}

void loop() 
{
  for( float i=0 ; i < 360.00 ; i++)
  {
 Serial.print(sin(i *(PI / 180.00)));
  Serial.print(" ");
   Serial.println(cos(i *(PI / 180.00)));

  }
 

}
