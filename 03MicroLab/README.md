## نمایش توابع سینوس و کسینوس در آردوینو
## تجهیزات مورد نیاز:
بورد آردوینو 

کابل USB

نرم افزار adruino
 ## کد برنامه: 
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
  ## شرح آزمایش: با تابع Serial.begin به پورت 9600 متصل می شویم.از سربرگ tools قسمت serial plotter را انتخاب کرده و روی 9600baud می گذاریم و بعد موج های سینوس و کسینوس نمایش داده می شوند.
 

}
