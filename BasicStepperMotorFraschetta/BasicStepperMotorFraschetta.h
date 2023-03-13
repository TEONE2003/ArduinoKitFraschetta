#ifndef BasicStepperMotorFraschetta_h
#define BasicStepperMotorFraschetta_h
#include <MotorSwipingFraschetta.h>
#include <EEPROMNumFraschetta.h>
class BasicStepperMotorF:MotorSwipingF{
protected:
 uint16_t MaximumSteps,ForwardPosition,BackPosition;
 EEPROMNumF::eeprom_uint16_t MP;
public:
 uint16_t shiftPeriodInMilliseconds;
 uint16_t Position()override{return MP.Value();}
 void MemorizeSteps(uint16_t Steps){
  if(Steps<MaximumSteps){
   MP.Value(Steps);
  }
  else{
   MP.Value(0);
  }
 }
 BasicStepperMotorF(uint16_t MaximumSteps,uint16_t shiftPeriodInMilliseconds,uint16_t INDIRIZZO_EEPROM_CELLA1_Position,uint16_t INDIRIZZO_EEPROM_CELLA2_Position){
  this->MaximumSteps=MaximumSteps;
  this->shiftPeriodInMilliseconds=shiftPeriodInMilliseconds;
  MP = EEPROMNumF::eeprom_uint16_t(EepromAddressCell1Position,EepromAddressCell2Position);
 }
 virtual void RightStep()=0;
 virtual void LeftStep()=0;
 void RightSteps(uint16_t Steps){
  for(uint16_t P=Position(); P<=Steps; P++){RightStep(); delay(shiftPeriodInMilliseconds);}
 }
 void LeftSteps(uint16_t Steps){
  for(uint16_t P=Position(); P>=Steps; P--){LeftStep(); delay(shiftPeriodInMilliseconds);}
 }
 void Position(uint16_t Position){RightSteps(Position); LeftSteps(Position);}
 void SwipeForward() override {Position(PositionForward);}
 void SwipeBack() override {Position(BackPosition);}
 void Swiping(uint16_t PositionForward,uint16_t BackPosition,uint16_t SwipeBack, UnitOfTime Unit){
  this->PositionForward = PositionForward;
  this->BackPosition = BackPosition;
  MotorSwiping::Swiping(SwipeBack,Unit);
 }
};
#endif
