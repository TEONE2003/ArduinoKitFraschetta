#ifndef ButtonFraschetta_h
#define ButtonFraschetta_h
#include <InputFraschetta.h>
#include <VirtualCycleFraschetta.h>
#include <DigitalTypeFraschetta.h>
class ButtonF:InputF,VirtualCycleF{
 protected: bool PreviousStatus;
 public:
  ButtonF(){}
  ButtonF(uint8_t Pin,uint64_t Delay=0,UnitOfTime Unit=Milliseconds,ResistanceMode ResistanceM=ExternalResistance,
  DigitalType DigitalReadM=NormalLogic):InputF(Pin,ResistanceM,DigitalReadM),VirtualCycleF(Delay,Unit){}
  bool Clicked(){
   if(nTick()){
    if(PreviousStatus==0 && DigitalRead()){
     PreviousStatus=1; return 1;
    }
    else if(DigitalRead() && PreviousStatus==1){PreviousStatus=1;}
   }
   return 0;
  }
  bool Pressed(){return DigitalRead();}
  void SetExternalResistance(){InputF::SetExternalResistance();}
  void SetPullUp(){InputF::SetPullUp();}
  void SetPullDown(){InputF::SetPullDown();}
};
#endif
