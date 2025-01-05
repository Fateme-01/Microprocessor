
int sevseg[10][7] =
{
  { 1 , 1 , 1 , 1 , 1 , 1 , 0 },    //0
  { 0 , 1 , 1 , 0 , 0 , 0 , 0 },
  { 1 , 1 , 0 , 1 , 1 , 0 , 1 },
  { 1 , 1 , 1 , 1 , 0 , 0 , 1 },
  { 0 , 1 , 1 , 0 , 0 , 1 , 1 },
  { 1 , 0 , 1 , 1 , 0 , 1 , 1 },    //5
  { 1 , 0 , 1 , 1 , 1 , 1 , 1 },
  { 1 , 1 , 1 , 0 , 0 , 0 , 0 },
  { 1 , 1 , 1 , 1 , 1 , 1 , 1 },
  { 1 , 1 , 1 , 1 , 0 , 1 , 1 }     //9
};
void printNumber(int number)
{
  for (int i = 0 ; i <= 7 ; i++)
  {
    digitalWrite(1 + i , sevseg[number][i]);
  }
}
void setup() {
  for (int j = 0 ; j <= 7 ; j++)
  {
    pinMode(j , OUTPUT);
  }
}
void loop() {
  for (int i = 0 ; i < 10 ; i++)
  {
    printNumber(i);
    delay(1000); }}
