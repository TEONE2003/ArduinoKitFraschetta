#include <VirtualCycleFraschetta.h>
VirtualCycleF C(2,Seconds);
void setup(){pinMode(13,OUTPUT);}
void loop(){for(uint64_t n=C.nTick();n>=1;n--){digitalWrite(13,!digitalRead(13));}}
