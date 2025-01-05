
#define T_C 262
#define T_D 294
#define T_A 440
#define T_B 493
const int D = 7;
const int C = 6;
const int A = 5;
const int B = 4;
const int Buzz = 11;
void setup()
{
  for ( int i = B; i <= D; i++)
   { pinMode(i, INPUT);
    digitalWrite(i, HIGH);}
}
void loop()
{
  while (digitalRead(D) == LOW)
   { tone(Buzz, T_D);}
  while (digitalRead(C) == LOW)
  {tone(Buzz, T_C);}
  while (digitalRead(A) == LOW)
  {tone(Buzz, T_A); }
   while (digitalRead(B) == LOW)
  { tone(Buzz, T_B);}
  
  noTone(Buzz);
}
