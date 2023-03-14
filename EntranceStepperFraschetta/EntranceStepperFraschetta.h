#ifndef EntranceStepperFraschetta_h
#define EntranceStepperFraschetta_h
#include <StepperMotorFraschetta.h>
#include <BasicEntranceStepperFraschetta.h>
class EntranceStepperF:StepperMotorF,public BasicEntranceStepperF{
 public:
  uint16_t Position(){return StepperMotorF::Position();}
  EntranceStepperF(uint8_t PinCheckStep,uint8_t PinVerse, boolean StatusPinToRight,uint16_t MaximumSteps,
  uint16_t ShiftPeriodInMilliseconds,uint16_t OpeningSteps,uint16_t ClosingSteps,uint16_t AddressMotionStatusPosition):
  BasicEntranceStepperF(MaximumSteps,OpeningSteps,ClosingSteps,ShiftPeriodInMilliseconds,PinCheckStep,PinVerse,AddressMotionStatusPosition),
  StepperMotorF(PinCheckStep,PinVerse,StatusPinToRight,MaximumSteps,ShiftPeriodInMilliseconds){
   CheckStatusMotion();
  }
};
#endif
