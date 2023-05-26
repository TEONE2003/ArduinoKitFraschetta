#ifndef VirtualStopwatchFraschetta_h
#define VirtualStopwatchFraschetta_h
#include "TimeFraschetta.h"
class VirtualStopwatchF{
protected:
bool Active;
uint64_t ST;
TimeF ET;
UnitOfTime StopwatchUnitOfTime;
public:
 void SetUnitOfTime(UnitOfTime Unit){StopwatchUnitOfTime = Unit;}
 VirtualStopwatchF(UnitOfTime Unit=Milliseconds){SetUnitOfTime(Unit); ST=0; ET=TimeF(); Active=0;}
 void Start(){if(!Active){Active=1; ST = micros();}}
 bool Started(){return Active;}
 void Stop(){Active=0;}
 TimeF ElapsedTime(){
  if(Active){
  if(ST<=micros()){ET = TimeF(micros()-ST,Microseconds);}
  else{ET=TimeF(0xFFFFFFFFFFFFFFFF-ST,Microseconds);}
  return ET.ConvertedTo(StopwatchUnitOfTime);
 }
 else{return TimeF(0,StopwatchUnitOfTime);}
}
};
#endif
