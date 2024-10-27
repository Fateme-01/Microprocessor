#define key1 digitalRed(A0)

void setup() 
{
 pinMode(A0, INPUT);
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
}

void loop() 
{
int i,a;
int dancinglight [ 6 ][ 5 ]=
{
  { 0 , 0 , 0 , 0 , 1 },
  { 0 , 0 , 0 , 1 , 1 },
  { 0 , 0 , 1 , 1 , 0 },
  { 0 , 1 , 1 , 0 , 0 },
  { 1 , 1 , 0 , 0 , 0 },
  { 1 , 0 , 0 , 0 , 0 },
       
};

if (key == 1)
{
  for (int a=0 ; a<=5 ; a++)
  {
    for (int i=0 ; i<=6 ; i++)
    digitalWrite (i , dancinglight [a][i] )
    delay(200)
  }

}

}

