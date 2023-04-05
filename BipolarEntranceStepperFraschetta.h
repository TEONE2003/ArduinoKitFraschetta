#ifndef BipolarEntranceStepperFraschetta_h
#define BipolarEntranceStepperFraschetta_h
#include "BipolarStepperMotorFraschetta.h"
#include "BasicEntranceStepperFraschetta.h"
class BipolarEntranceStepperF:public BipolarStepperMotorF,public BasicEntranceStepperF{
 public:
    using BipolarStepperMotorF::Position;
    void Begin(){BipolarStepperMotorF::Begin(); BasicEntranceStepperF::CheckStatusMotion();}
    BipolarEntranceStepperF(uint16_t MaximumSteps,uint8_t PinA,uint8_t PinB,uint8_t PinC,uint8_t PinD,
   uint16_t OpeningSteps,uint16_t ClosingSteps,uint8_t shiftPeriodInMilliseconds):
    BipolarStepperMotorF(MaximumSteps,shiftPeriodInMilliseconds,PinA,PinB,PinC,PinD),
   BasicEntranceStepperF(MaximumSteps,OpeningSteps,ClosingSteps,shiftPeriodInMilliseconds,PinA,PinB,PinC){}
};
#endif
