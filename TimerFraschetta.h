#ifndef TimerFraschetta_h
#define TimerFraschetta_h
#include "TimeFraschetta.h"
#include "VirtualStopwatchFraschetta.h"
enum TimerType{NotBlocking,Blocking};
class TimerF:VirtualStopwatchF{
 protected: TimeF Period; TimerType TimerT;
 public:
  using VirtualStopwatchF::Start;
  using VirtualStopwatchF::Started;
  using VirtualStopwatchF::Stop;
  using VirtualStopwatchF::ElapsedTime;
  void SetPeriodAndTimeUnit(uint64_t Period,UnitOfTime Unit){
  SetUnitOfTime(Unit);
  this->Period = TimeF(Period,Unit);
  this->Period.ConvertTo(Microseconds);
}
void SetTimerType(TimerType Type){TimerT=Type;}
bool Stopped(){
 if(VirtualStopwatchF::Active){
  if(TimerT==NotBlocking){if(ElapsedTime()>=Period){VirtualStopwatchF::Stop(); return 1;} return 0;}
  else{Wait(Period); return 1;}
 }
 return 0;
}
TimerF(uint64_t Period,UnitOfTime Unit=Seconds,TimerType Type=NotBlocking):VirtualStopwatchF(Unit)
 {SetPeriodAndTimeUnit(Period,Unit);  SetTimerType(Type);}
TimerF(){}
};
#endif
