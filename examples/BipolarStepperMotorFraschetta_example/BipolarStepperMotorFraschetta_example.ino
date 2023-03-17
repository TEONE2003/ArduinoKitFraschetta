#include "BipolarStepperMotorFraschetta.h"
BipolarStepperMotorF M(2,3,4,5,512,0);
void setup(){Serial.begin(9600);}
void loop(){
delay(1000);
M.Position(511);
Serial.println(M.Position());
delay(1000);
M.Position(10);
Serial.println(M.Position());
}
