#include "PhysicalEntranceFraschetta.h"
PhysicalEntranceF Door(2,3);
void setup(){Serial.begin(9600);}
void loop(){
if(Door.Opened()){
 Serial.println("Opened");
}
else if(Door.Closed()){
Serial.println("Closed");
}
}