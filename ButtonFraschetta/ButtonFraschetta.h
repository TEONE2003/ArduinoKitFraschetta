#ifndef ButtonFraschetta_h
#define ButtonFraschetta_h
#include <InputFraschetta.h>
#include <VirtualCycleFraschetta.h>
class ButtonF:InputF,VirtualCycleF{
 protected:
  boolean PreviousStatus;
 public:
  ButtonF(){}
  ButtonF(uint8_t Pin,uint64_t Delay,UnitOfTime Unit):InputF(Pin),CicloVirtualeF(Delay,Unit){}
  ButtonF(uint8_t Pin,uint64_t Delay,UnitOfTime Unit,ResistanceMode ResistanceM):InputF(Pin,ResistanceM),CicloVirtualeF(Delay,Unit){}
  ButtonF(uint8_t Pin,uint64_t Delay,UnitOfTime Unit,DigitalType DigitalReadingM):InputF(Pin,DigitalReadingM),CicloVirtualeF(Delay,Unit){}
  ButtonF(uint8_t Pin,uint64_t Delay,UnitOfTime Unit,ResistanceMode ResistanceM,
  DigitalType DigitalReadingM):InputF(Pin,ResistanceM,DigitalReadingM),CicloVirtualeF(Delay,Unit){}
  boolean Clicked(){
   if(Tick()){
    if(PreviousStatus && DigitalReading()){
     PreviousStatus=0; return 1;
    }
   }
   if(DigitalReading() && PreviousStatus==0){PreviousStatus=1;}
   return 0;
  }
  void ExternalResistance(){InputF::ExternalResistance();}
  void PullUp(){InputF::PullUp();}
  void PullDown(){InputF::PullDown();}
};
#endif
