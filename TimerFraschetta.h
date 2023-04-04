#ifndef TimerFraschetta_h
#define TimerFraschetta_h
#include "TimeFraschetta.h"
#include "VirtualStopwatchFraschetta.h"
enum TimerType{NotBlocking,Blocking};
class TimerF:VirtualStopwatchF{
 protected:
  TimeF Period;
  TimerType TimerT;
  boolean En,InizializedT;
 public:
  boolean Inizialized(){return InizializedT;}
  void Enable(){if(TimerT==NotBlocking){Start(); En=1;}}
  boolean Enabled(){return En;}
  void Disable(){Stop(); En=0;}
  TimeF ElapsedTime(){return ElapsedTime();}
  void SetPeriodAndTimeUnit(uint64_t Period,UnitOfTime Unit){
  SetUnitOfTime(Unit);
  this->Period = TimeF(Period,Unit);
  this->Period.ConvertTo(Microseconds);
}
void SetTimerType(TimerType Type){TimerT=Type;}
boolean Stop(){
 switch(TimerT){
  case NotBlocking: if(ElapsedTime()>=Period){Disable(); return 1;}
    return 0;
  case Blocking: Wait(Period);
    return 1;
    }
}
TimerF(uint64_t Period=0,UnitOfTime Unit=Seconds,TimerType Type=NotBlocking):VirtualStopwatchF(Unit)
 {SetPeriodAndTimeUnit(Period,Unit);  SetTimerType(Type); InizializedT=1; En=0;}
};
#endif
