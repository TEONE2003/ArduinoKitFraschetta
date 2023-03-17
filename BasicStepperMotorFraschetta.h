#ifndef BasicStepperMotorFraschetta_h
#define BasicStepperMotorFraschetta_h
#include <MotorSwipingFraschetta.h>
#include <EepromNumFraschetta.h>
class BasicStepperMotorF:MotorSwipingF{
protected:
 uint16_t MaximumSteps,ForwardPosition,BackPosition;
 EepromNumF::EepromUint16T MP;
public:
 uint16_t ShiftPeriodInMilliseconds;
 uint16_t Position()override{return MP.Value();}
 void MemorizeSteps(uint16_t Steps){
  if(Steps<MaximumSteps){
   MP.Value(Steps);
  }
  else{
   MP.Value(0);
  }
 }
 BasicStepperMotorF(uint16_t MaximumSteps,uint16_t ShiftPeriodInMilliseconds,uint16_t EepromAddressCell1Position,uint16_t EepromAddressCell2Position){
  this->MaximumSteps=MaximumSteps;
  this->ShiftPeriodInMilliseconds=ShiftPeriodInMilliseconds;
  MP = EepromNumF::EepromUint16T(EepromAddressCell1Position,EepromAddressCell2Position);
 }
 virtual void RightStep()=0;
 virtual void LeftStep()=0;
 void RightSteps(uint16_t Steps){
  for(uint16_t P=Position(); P<=Steps; P++){RightStep(); delay(ShiftPeriodInMilliseconds);}
 }
 void LeftSteps(uint16_t Steps){
  for(uint16_t P=Position(); P>=Steps; P--){LeftStep(); delay(ShiftPeriodInMilliseconds);}
 }
 void Position(uint16_t Position){RightSteps(Position); LeftSteps(Position);}
 void ForwardSwipe() override {Position(ForwardPosition);}
 void BackSwipe() override {Position(BackPosition);}
 void Swiping(uint16_t ForwardPosition,uint16_t BackPosition,uint16_t BackSwipe, UnitOfTime Unit){
  this->ForwardPosition = ForwardPosition;
  this->BackPosition = BackPosition;
  MotorSwipingF::Swiping(BackSwipe,Unit);
 }
};
#endif
