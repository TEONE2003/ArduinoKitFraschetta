#ifndef PhysicalEntranceFraschetta_h
#define PhysicalEntranceFraschetta_h
#include <ButtonFraschetta.h>
class PhysicalEntranceF{
protected:
  ButtonF ButtonOpeningLimitSwitch;
  ButtonF ButtonClosingLimitSwitch;
 public:
  PhysicalEntranceF(uint8_t PinOpeningLimitSwitch,uint8_t PinClosingLimitSwitch,uint64_t DelayLimitSwitch1,UnitOfTime UnitLimitSwitch1,
                    uint64_t DelayLimitSwitch2,UnitOfTime UnitLimitSwitch2){
   ButtonOpeningLimitSwitch = ButtonF(PinOpeningLimitSwitch,DelayLimitSwitch1,UnitLimitSwitch1);
   ButtonClosingLimitSwitch = ButtonF(PinClosingLimitSwitch,DelayLimitSwitch2,UnitLimitSwitch2);
  }
  PhysicalEntranceF(uint8_t PinOpeningLimitSwitch,uint8_t PinClosingLimitSwitch,uint64_t DelayLimitSwitch,UnitOfTime UnitLimitSwitch):
      PhysicalEntranceF(PinOpeningLimitSwitch,PinClosingLimitSwitch,DelayLimitSwitch,UnitLimitSwitch,DelayLimitSwitch,UnitLimitSwitch){}
  boolean Opened(){return ButtonOpeningLimitSwitch.Pressed();}
  boolean Closed(){return ButtonClosingLimitSwitch.Pressed();}
};
#endif
