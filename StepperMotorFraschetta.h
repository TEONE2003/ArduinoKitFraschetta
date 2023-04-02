#ifndef StepperMotorFraschetta_h
#define StepperMotorFraschetta_h
#include "BasicStepperMotorFraschetta.h"
class StepperMotorF:public BasicStepperMotorF{
protected:
 uint8_t PinControlStep,PinTowards;
 boolean StatePinTowardsRight;
 void Step(){
  digitalWrite(PinControlStep,HIGH);
  delay(2);
  digitalWrite(PinControlStep,LOW);
 }
public:
 void LeftStep()override{digitalWrite(PinTowards,StatePinTowardsRight); Step(); MemorizeSteps(Position()-1);}
 void RightStep()override{digitalWrite(PinTowards,!StatePinTowardsRight); Step(); MemorizeSteps(Position()+1);}
 StepperMotorF(uint8_t PinControlStep,uint8_t PinTowards, boolean StatePinTowardsRight, uint16_t MaximumSteps,uint16_t ShiftPeriodInMilliseconds):
  BasicStepperMotorF(MaximumSteps,ShiftPeriodInMilliseconds,PinControlStep,PinTowards){
   this->PinControlStep=PinControlStep; this->PinTowards=PinTowards;
  }
 void Begin(){pinMode(PinControlStep,OUTPUT); pinMode(PinTowards,OUTPUT);}
};
#endif
