#ifndef VirtualCycleFraschetta_h
#define VirtualCycleFraschetta_h
#include <VirtualStopwatchFraschetta.h>
class VirtualCycleF:VirtualStopwatchF{
protected: TimeF Period; uint64_t Divider;
public:
    VirtualCycleF(uint64_t Period=0,UNITA_DI_TimeF Unit=MILLISECONDI):VirtualStopwatchF(Unit){this->Period=TimeF(Period,Unit);}
 TimeF ElapsedTime(){return VirtualStopwatchF::ElapsedTime();}
 uint64_t nTick(){
  Start();
  Divider=ElapsedTime()/Period;
  if(Divider>=1){Stop();}
  return Divider;
 }
};
#endif
