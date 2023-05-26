#ifndef PhotoresistorFraschetta_h
#define PhotoresistorFraschetta_h
#include "TimerFraschetta.h"
#include "SerialBeginFraschetta.h"
class PhotoresistorF:TimerF{
private: CheckChangeF<bool>Change; VirtualCycleF *C=nullptr; uint8_t Pin;
protected:
 uint16_t TurnOnThreshold,TurnOffThreshold;
 bool LastCheckExecuted;
public:
 PhotoresistorF(uint8_t Pin,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit):TimerF(Delay,Unit){
  this->TurnOnThreshold = TurnOnThreshold;
  this->TurnOffThreshold = TurnOffThreshold;
  LastCheckExecuted=1;
  Change=CheckChangeF<bool>(false);
  this->Pin=Pin;
 }
 uint16_t ReadPhotoresistor(){return analogRead(Pin);}
 void Calibrate(){C=malloc(sizeof(VirtualCycleF)); *C=VirtualCycleF(1,Seconds); if(C->nTick()){SerialBeginF(); Serial.print("Photoresistor: "+String(ReadPhotoresistor())+"\n");}}
 bool Light(){
  bool TurnOffThresholdReached=ReadPhotoresistor()>=TurnOffThreshold;
  bool TurnOnThresholdReached=ReadPhotoresistor()<=TurnOnThreshold;
  if(TurnOffThresholdReached||TurnOnThresholdReached){Start();}
  if(Stopped()){
   if(TurnOffThresholdReached){LastCheckExecuted=1; return 1;}
   if(TurnOnThresholdReached){LastCheckExecuted=0; return 0;}
  }
 return LastCheckExecuted;
 }
 bool NoLight(){return !Light();}
 bool LightChanged(){return Change.Changed(Light());}
 void Begin(){pinMode(Pin,INPUT); Change=CheckChangeF<bool>(Light());}
};
#endif
