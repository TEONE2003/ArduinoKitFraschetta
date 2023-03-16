#include <LedFraschetta.h>
#include <VirtualCycleFraschetta.h>

VirtualCycleF C(2,Seconds);
LedF L(13);
void setup(){}
void loop(){for(uint64_t n=C.nTick(),n>=1,n--;){L.InvertStatus();}}
