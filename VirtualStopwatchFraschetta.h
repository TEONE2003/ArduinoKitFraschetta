#ifndef VirtualStopwatchFraschetta_h
#define VirtualStopwatchFraschetta_h
#include <TimeFraschetta.h>
class VirtualStopwatchF{
protected:
boolean ActiveStopwatch;
uint64_t CurrentMicroseconds;
TimeF It,ET;
UnitOfTime StopwatchUnitOfTime;
public:
void SetUnitOfTime(UnitOfTime Unit){StopwatchUnitOfTime = Unit;}
VirtualStopwatchF(UnitOfTime Unit=Milliseconds){SetUnitOfTime(Unit); It = TimeF(0,Microseconds); ET=It; CurrentMicroseconds=0; ActiveStopwatch=0;}
void Start(){if(!ActiveStopwatch){ActiveStopwatch=1; It.Value = micros();}}
void Stop(){ActiveStopwatch=0;}
TimeF ElapsedTime(){
if(ActiveStopwatch){
if(It.Value>=CurrentMicroseconds){ET = TimeF(CurrentMicroseconds-It.Value,Microseconds);}
else{ET=TimeF(0xFFFFFFFFFFFFFFFF-It.Value,Microseconds);}
return ET.ConvertedTo(StopwatchUnitOfTime);
}
else{return TimeF(0,StopwatchUnitOfTime);}
}
};
#endif
