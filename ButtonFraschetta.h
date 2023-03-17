#ifndef ButtonFraschetta_h
#define ButtonFraschetta_h
#include <InputFraschetta.h>
#include <VirtualCycleFraschetta.h>
#include <DigitalTypeFraschetta.h>
class ButtonF:InputF,VirtualCycleF{
 protected: bool PreviousStatus,SavePressed;
 public:
  ButtonF(){}
  ButtonF(uint8_t Pin,uint64_t Delay=0,UnitOfTime Unit=Milliseconds,ResistanceMode ResistanceM=ExternalResistance,
  DigitalType DigitalReadM=NormalLogic):InputF(Pin,ResistanceM,DigitalReadM),VirtualCycleF(Delay,Unit){}
  bool Clicked(){
   if(nTick()){
    if(PreviousStatus==0 && DigitalRead()){PreviousStatus=1;}
    else if(DigitalRead()==0 && PreviousStatus){PreviousStatus=0; return 1;}
   }
   return PreviousStatus;
  }
  bool Pressed(){
   if(nTick()){SavePressed=DigitalRead();}
   return SavePressed;
  }
  void SetExternalResistance(){InputF::SetExternalResistance();}
  void SetPullUp(){InputF::SetPullUp();}
  void SetPullDown(){InputF::SetPullDown();}
};
#endif
