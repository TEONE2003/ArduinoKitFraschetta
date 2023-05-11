#ifndef PhotoresistorFraschetta_h
#define PhotoresistorFraschetta_h
#include "InputFraschetta.h"
#include "VirtualCycleFraschetta.h"
#include "ExecuteOnceFraschetta.h"
class PhotoresistorF:InputF,VirtualCycleF{
private: CheckChangeF<bool>Change;
protected:
 uint16_t TurnOnThreshold,TurnOffThreshold;
 bool LastCheckExecuted;
public:
 PhotoresistorF(uint8_t Pin,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit):InputF(Pin),VirtualCycleF(Delay,Unit){
  this->TurnOnThreshold = TurnOnThreshold;
  this->TurnOffThreshold = TurnOffThreshold;
  LastCheckExecuted=1;
  Change=CheckChangeF<bool>(false);
 }
 uint16_t ReadPhotoresistor(){return AnalogRead();}
 void Calibrate(){static VirtualCycleF C=VirtualCycleF(1,Seconds); if(C.nTick()){static ExecuteOnceF IS=ExecuteOnceF(); if(IS.NoExecuted()){Serial.end(); Serial.begin(9600);} Serial.print("Photoresistor: "+String(ReadPhotoresistor())+"\n");}}
 bool Light(){
 if(nTick()){
  if(ReadPhotoresistor()>=TurnOffThreshold){LastCheckExecuted=1; return 1;}
  if(ReadPhotoresistor()<=TurnOnThreshold){LastCheckExecuted=0; return 0;}
 }
 return LastCheckExecuted;
 }
 bool NoLight(){return !Light();}
 bool LightChanged(){return Change.Changed(Light());}
 void Begin(){Change=CheckChangeF<bool>(Light()); InputF::Begin();}
};
#endif
