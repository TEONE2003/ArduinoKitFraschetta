#ifndef PhysicalEntranceFraschetta_h
#define PhysicalEntranceFraschetta_h
#include <ButtonFraschetta.h>
class PhysicalEntranceF{
 protected:
  Button ButtonOpeningLimitSwitch;
  Button ButtonClosingLimitSwitch;
 public:
  PhysicalEntranceF(uint8_t PinOpeningLimitSwitch,uint8_t PinClosingLimitSwitch,uint64_t DelayLimitSwitch1,UnitOfTime UnitLimitSwitch1,
  uint64_t DelayLimitSwitch2,UnitOfTime UnitLimitSwitch2){
  ButtonOpeningLimitSwitch = Button(PinOpeningLimitSwitch,DelayLimitSwitch1,UnitLimitSwitch1);
  ButtonClosingLimitSwitch = Button(PinClosingLimitSwitch,DelayLimitSwitch2,UnitLimitSwitch2);
  }
  PhysicalEntranceF(uint8_t PinOpeningLimitSwitch,uint8_t PinClosingLimitSwitch,uint64_t DelayLimitSwitch,UnitOfTime UnitLimitSwitch):
  PhysicalEntranceF(PinOpeningLimitSwitch,PinClosingLimitSwitch,DelayLimitSwitch,UnitLimitSwitch,DelayLimitSwitch,UnitLimitSwitch){}
  boolean Opened(){return ButtonOpeningLimitSwitch.Clicked();}
  boolean Closed(){return ButtonClosingLimitSwitch.Clicked();}
};
#endif
