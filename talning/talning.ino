#include "SevSeg.h"
SevSeg sevseg;
int i = 0;
void setup()
{
  //Set to 1 for single digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};

  //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {10, 9, 8, 5, 4, 2, 3, 7};
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  //sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
}

void loop()
{ 
   //Display numbers one by one with 2 seconds delay
  
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(2000);
     i++;
     if (i == 10){i = 0;}
   
}
