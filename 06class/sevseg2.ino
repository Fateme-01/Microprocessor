#include <SevSeg.h>
#include "SevSeg.h"
SevSeg sevseg;
 
void setup()
{
    byte numDigits = 1;
    byte digitPins[] = {};                                                                                                      
    byte segmentPins[] = {3, 2, 8, 7, 6, 4, 5, 9};
    bool resistorsOnSegments = true;
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}
 
void loop()
{ 
   for(int i = 0; i < 10; i++)
   {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(1000);
   }
}
