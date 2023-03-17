#ifndef VirtualCycleFraschetta_h
#define VirtualCycleFraschetta_h
#include <VirtualStopwatchFraschetta.h>
class VirtualCycleF:VirtualStopwatchF{
protected: TimeF Period; uint64_t Divider; bool I;
public:
 VirtualCycleF(){}
 VirtualCycleF(uint64_t Period,UnitOfTime Unit):VirtualStopwatchF(Unit){I=1; this->Period=TimeF(Period,Unit);}
 bool Inizialized(){return I;}
 TimeF ElapsedTime(){return VirtualStopwatchF::ElapsedTime();}
 uint64_t nTick(){
  Start();
  Divider=ElapsedTime()/Period;
  if(Divider>=1){Stop();}
  return Divider;
 }
};
#endif
