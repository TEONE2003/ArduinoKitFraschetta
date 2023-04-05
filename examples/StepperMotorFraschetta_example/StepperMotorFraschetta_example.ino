#include "StepperMotorFraschetta.h"
StepperMotorF SM(2,3,1,200,10);
void setup(){SM.Begin(); SM.LeftSteps(100); delay(1000); SM.RightSteps(100);}
void loop(){}
