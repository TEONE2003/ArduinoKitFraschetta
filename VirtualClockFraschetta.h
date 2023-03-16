#ifndef VirtualClockFraschetta_h
#define VirtualClockFraschetta_h
#include <TimeFraschetta.h>
#include <VirtualStopwatchFraschetta.h>
class VirtualClockF:VirtualStopwatchF{
protected:
 TimestampF O;
public:
 VirtualClockF(uint64_t Hours=0,uint64_t Minutes=0,uint64_t Seconds=0,uint64_t Milliseconds=0,uint64_t Microseconds=0,uint64_t Nanoseconds=0):VirtualStopwatchF(Microseconds){
  O=TimestampF(NANOSeconds,Microseconds,Milliseconds,Seconds,Minutes,ORA);
 }
 TimestampF ReadTimestamp(){O = TimestampF(ElapsedTime()); return O;}
};
#endif
