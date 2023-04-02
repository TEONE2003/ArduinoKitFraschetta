#ifndef BipolarStepperMotorFraschetta_h
#define BipolarStepperMotorFraschetta_h
#include "BasicStepperMotorFraschetta.h"
class BipolarStepperMotorF:public BasicStepperMotorF{
protected:
 uint8_t PinA,PinB,PinC,PinD;
 void Stop(){
  digitalWrite(PinA,0); digitalWrite(PinB,0);
  digitalWrite(PinC,0); digitalWrite(PinD,0);
 }
 void RightStep(uint8_t Step){
  digitalWrite(PinA,Step==1);
  digitalWrite(PinB,Step==2);
  digitalWrite(PinC,Step==3);
  digitalWrite(PinD,Step==4);
  delay(4);
 }
 void LeftStep(uint8_t Step){
  digitalWrite(PinA,Step==1);
  digitalWrite(PinB,Step==4);
  digitalWrite(PinC,Step==3);
  digitalWrite(PinD,Step==2);
  delay(4);
 }
public:
 void RightStep()override{
  RightStep(1);
  RightStep(2);
  RightStep(3);
  RightStep(4);
  MemorizeSteps(Position()+1);
  Stop();
 }
 void LeftStep()override{
  LeftStep(1);
  LeftStep(2);
  LeftStep(3);
  LeftStep(4);
  MemorizeSteps(Position()-1);
  delay(ShiftPeriodInMilliseconds);
  Stop();
 }
  BipolarStepperMotorF(uint8_t PinA,uint8_t PinB,uint8_t PinC,uint8_t PinD,uint16_t MaximumSteps,uint16_t ShiftPeriodInMilliseconds):
  BasicStepperMotorF(MaximumSteps,ShiftPeriodInMilliseconds,PinA,PinB){
   this->PinA=PinA; this->PinB=PinB; this->PinC=PinC; this->PinD=PinD;
  }
    void Begin(){pinMode(PinA,OUTPUT); pinMode(PinB,OUTPUT); pinMode(PinC,OUTPUT); pinMode(PinD,OUTPUT);}
};
#endif
