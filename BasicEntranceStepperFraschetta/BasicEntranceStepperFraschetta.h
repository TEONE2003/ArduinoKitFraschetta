#ifndef BasicEntranceStepperFraschetta_h
#define BasicEntranceStepperFraschetta_h
#include <BasicStepperMotorFraschetta.h>
#include <MotorizedEntranceFraschetta.h>
class BasicEntranceStepperF:BasicStepperMotorF,public MotorizedEntranceF{
 public:
  virtual uint16_t Position()=0;
  void Opened override {
   MemorizeStatus(Opening);
   BasicStepperMotorF::Position(OpeningLimitSwitch);
  }
  void Close() override {
   MemorizeStatus(Closing);
   BasicStepperMotorF::Position(ClosingLimitSwitch);
  }
  boolean Opened() override {return Position()==OpeningLimitSwitch;}
  boolean Closed() override {return Position()==ClosingLimitSwitch;}
  BasicEntranceStepperF(uint16_t MaximumSteps,uint16_t OpeningSteps,uint16_t ClosingSteps,
  uint16_t ShiftPeriodInMilliseconds,uint16_t EepromAddressCell1Position,uint16_t EepromAddressCell2Position,uint16_t AddressMotionStatusPosition):
   BasicStepperMotorF(MaximumSteps,ShiftPeriodInMilliseconds,EepromAddressCell1Position,EepromAddressCell1Position),
   MotorizedEntranceF(OpeningSteps,ClosingSteps,AddressMotionStatusPosition){}
};
#endif
