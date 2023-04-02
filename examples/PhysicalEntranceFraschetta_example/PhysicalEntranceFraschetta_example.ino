#include "PhysicalEntranceFraschetta.h"
PhysicalEntranceF Door(2,3,10,Milliseconds);
void setup(){Serial.begin(9600); Door.Begin();}
void loop(){
if(Door.Opened()){Serial.println("Opened");}
else if(Door.Closed()){Serial.println("Closed");}
}