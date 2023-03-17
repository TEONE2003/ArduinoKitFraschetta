#include "EntranceStepperFraschetta.h"
EntranceStepperF M(2,3,1,200,10,100,50,0);
void setup(){
M.Open(); Serial.println(M.Opened());
delay(5000);
M.Close(); Serial.println(M.Closed());
}
void loop(){}
