#ifndef PhotoresistorFraschetta_h
#define PhotoresistorFraschetta_h
#include "InputFraschetta.h"
#include "VirtualCycleFraschetta.h"
class PhotoresistorF:InputF,VirtualCycleF{
protected:
 uint16_t TurnOnThreshold,TurnOffThreshold;
 bool LastCheckExecuted;
public:
 PhotoresistorF(uint8_t Pin,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit):InputF(Pin),VirtualCycleF(Delay,Unit){
  this->TurnOnThreshold = TurnOnThreshold;
  this->TurnOffThreshold = TurnOffThreshold;
  LastCheckExecuted=false;
 }
 uint16_t ReadPhotoresistor(){return AnalogRead();}
 void Calibrate(){static bool SerialInizialized=false; if(!SerialInizialized){Serial.end(); Serial.begin(9600); SerialInizialized=true;} Serial.print("Photoresistor: "+String(ReadPhotoresistor())+"\n");}
 boolean Check(){
 if(nTick()){
  if(ReadPhotoresistor()<=TurnOnThreshold){LastCheckExecuted=1; return 1;}
  if(ReadPhotoresistor()>=TurnOffThreshold){ LastCheckExecuted=0; return 0;}
  return LastCheckExecuted;
 }
 return LastCheckExecuted;
 }
 using InputF::Begin;
};
#endif
