#ifndef EntranceStepperFraschetta_h
#define EntranceStepperFraschetta_h
#include "StepperMotorFraschetta.h"
#include "BasicEntranceStepperFraschetta.h"
class EntranceStepperF:StepperMotorF,public BasicEntranceStepperF{
protected: using StepperMotorF::LeftStep; using StepperMotorF::RightStep;
public:
  using StepperMotorF::Position; using StepperMotorF::Begin;
  EntranceStepperF(uint8_t PinControlStep,uint8_t PinVerse, boolean StatusPinToRight,uint16_t MaximumSteps,
  uint16_t ShiftPeriodInMilliseconds,uint16_t OpeningSteps,uint16_t ClosingSteps,uint16_t AddressMotionStatusPosition):
  BasicEntranceStepperF(MaximumSteps,OpeningSteps,ClosingSteps,ShiftPeriodInMilliseconds,PinControlStep,PinVerse,AddressMotionStatusPosition),
  StepperMotorF(PinControlStep,PinVerse,StatusPinToRight,MaximumSteps,ShiftPeriodInMilliseconds){CheckStatusMotion();}
};
#endif
