#ifndef TimestampFraschetta_h
#define TimestampFraschetta_h
#include <TimeFraschetta.h>
struct TimestampF{
protected:
 double Nanosec,Microsec,Millisec,Sec,O,M;
public:

void hours(uint64_t Hours){O = Hours;}
    
void Minutes(uint64_t Minutes){
 TEMPO T(Minutes,Minutes);
 if(Minutes>59){
  O += T.Hours();
  M += T.Remainder();
 }
 else{M += Minutes;}
}

void Seconds(uint64_t Seconds){
 TEMPO T(Seconds,Seconds);
 if(Seconds > 59){Minutes(T.Minutes()); Sec += T.Remainder();}
 else{Sec += T.Value;}
}

void Milliseconds(uint64_t Milliseconds){
 TEMPO T(Milliseconds,Milliseconds);
 if(Milliseconds > 999){Seconds(T.Seconds()); Millisec += T.Remainder();}
 else{Millisec += T.Value;}
}

void Microseconds(uint64_t Microseconds){
 TEMPO T(Microseconds,Microseconds);
 if(Microseconds > 999){Milliseconds(T.Milliseconds()); Microsec += T.Remainder();}
 else{Microsec += T.Value;}
}
    
void Nanoseconds(uint64_t Nanoseconds){
 TEMPO T(Nanoseconds,Nanoseconds);
 if(Nanoseconds > 999){Microseconds(T.Microseconds()); Nanosec += T.Remainder();}
 else{Nanosec += T.Value;}
}
      
uint64_t  Nanoseconds(){return Nanosec;}
uint64_t  Microseconds(){return Microsec;}
uint64_t  Milliseconds(){return Millisec;}
uint64_t  Seconds(){return Sec;}
uint64_t  Minutes(){return M;}
uint64_t  Hours(){return O;}
TimestampF(uint64_t Hours=0,uint64_t Minutes=0,uint64_t Seconds=0,uint64_t Milliseconds=0,uint64_t Microseconds=0,uint64_t Nanoseconds=0)
{this->Nanoseconds=Nanoseconds; this->Microseconds=Microseconds; this->Milliseconds=Milliseconds; this->Seconds=Seconds; this->Minutes=Minutes; this->Hours=Hours;}
TimestampF(TEMPO TimeToSet){this->Nanoseconds(TimeToSet.Nanoseconds());}
};
#endif
