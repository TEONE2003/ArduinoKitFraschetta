#ifndef ServoEntranceFraschetta_h
#define ServoEntranceFraschetta_h
#include "ServomotorFraschetta.h"
#include "MotorizedEntranceFraschetta.h"
class ServoEntranceF:ServomotorF,MotorizedEntranceF{
 protected:
  uint16_t MovementDelayInMilliseconds;
 public:
  void MovementStatusCheck(){MotorizedEntranceF::MovementStatusCheck();}
    void Open() override {
    MemorizeStatus(Opening);
    SetPosition(OpeningLimitSwitch,MovementDelayInMilliseconds);
   }
   void Close() override {
    MemorizeStatus(Closing);
    SetPosition(ClosingLimitSwitch,MovementDelayInMilliseconds);
   }
    boolean Opened() override {return Position()==OpeningLimitSwitch;}
    boolean Closed() override {return Position()==ClosingLimitSwitch;}
   ServoEntranceF(uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,uint16_t AddressMotionStatusPosition,
   uint16_t MovementDelayInMilliseconds):ServomotorF(Pin),MotorizedEntranceF(OpeningPosition,ClosingPosition,AddressMotionStatusPosition){
   this->MovementDelayInMilliseconds = MovementDelayInMilliseconds;}
};
#endif
