#ifndef PhotoresistorFraschetta_h
#define PhotoresistorFraschetta_h
#include "InputFraschetta.h"
#include "VirtualCycleFraschetta.h"
class PhotoresistorF:InputF,VirtualCycleF{
protected:
 uint16_t TurnOnThreshold,TurnOffThreshold;
 boolean LastCheckExecuted;
public:
 PhotoresistorF(uint8_t Pin,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit):InputF(Pin),VirtualCycleF(Delay,Unit){
  this->TurnOnThreshold = TurnOnThreshold;
  this->TurnOffThreshold = TurnOffThreshold;
 }
 uint16_t ReadPhotoresistor(){return AnalogRead();}
 boolean Check(){
 if(nTick()){
  if(ReadPhotoresistor()>=TurnOnThreshold){LastCheckExecuted=1; return 1;}
  if(ReadPhotoresistor()<=TurnOnThreshold && ReadPhotoresistor()>=TurnOffThreshold){ return LastCheckExecuted;}
  LastCheckExecuted=0; return 0;
 }
 return LastCheckExecuted;
 }
};
#endif
