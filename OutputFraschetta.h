#ifndef OutputFraschetta_h
#define OutputFraschetta_h
#include "DigitalTypeFraschetta.h"
#include "VirtualCycleFraschetta.h"
#include "TimerFraschetta.h"
#include "EEPROM.h"
#include "CheckChangeFraschetta.h"
enum MemorizeStatus:boolean{DoNotSaveStatus=0,SaveStatus=1};
class OutputF{
protected:
 uint8_t Pin;
 DigitalType TypeD;
 MemorizeStatus Save;
 CheckChangeF<bool>Change;
public:
 void SetStatus(uint8_t Percentage){
  bool P=Percentage>=100;
  if(P){digitalWrite(Pin,TypeD);}
  else if(Percentage==0){digitalWrite(Pin,!TypeD);}
  else{analogWrite(Pin,(Percentage*255)/100);}
  if(Save){
  if(P){EEPROM.update(Pin,100);}
  else{EEPROM.update(Pin,Percentage);}
 }
}
 bool DigitalRead(){
  bool r=digitalRead(Pin);
  if(TypeD){return r;}
  else{return !r;}
 }
 uint8_t ReadAnalogStatusPercentage(){return (analogRead(Pin)*255)/100;}
 void Begin(){
  pinMode(Pin,OUTPUT);
  Change=CheckChangeF<bool>(DigitalRead());
  if(Save){
   if(EEPROM.read(Pin)>100){EEPROM.update(Pin,0);}
   SetStatus(EEPROM.read(Pin));
  }
  else{
   if(TypeD){digitalWrite(Pin,0);}
   else{digitalWrite(Pin,1);}
  }
 }
 void SetAnalogStatus(uint8_t StatusPercentage){SetStatus((StatusPercentage*100)/255);}
OutputF(){}
OutputF(uint8_t Pin,DigitalType TypeD=NormalLogic,MemorizeStatus Save=DoNotSaveStatus){
 this->TypeD=TypeD; this->Save=Save; this->Pin=Pin; Change=CheckChangeF<bool>(false);
}
OutputF(uint8_t Pin,MemorizeStatus Save):OutputF(Pin,NormalLogic,Save){}
 void TurnOn(){SetStatus(100);}
 void TurnOff(){SetStatus(0);}
 void SetStatusWithDelay(uint8_t Percentage,uint64_t Delay,UnitOfTime Unit){
  Wait(Delay,Unit); SetStatus(Percentage);
 }
 void SetStatusWhenTimerExpires(uint8_t Percentage,uint64_t Delay,UnitOfTime Unit){
  static TimerF Period=TimerF(Delay,Unit);
  if(!Period.Enabled()){Period.Enable();}
  if(Period.Stop()){SetStatus(Percentage);}
 }
 void TurnOnWithFade(uint8_t MaximumPercentage,uint16_t Time,UnitOfTime Unit){
  for(uint8_t P=0;P<MaximumPercentage;P++){
   Wait(Time,Unit); SetStatus(P);
  }
 }
 void TurnOffWithFade(uint8_t MaximumPercentage,uint16_t Time,UnitOfTime Unit){
  for(uint8_t P=MaximumPercentage;P>0;P--){
   Wait(Time,Unit); SetStatus(P);
  }
 }
void InvertStatus(){
 if(Save){
  uint8_t S=EEPROM.read(Pin);
  if(S==100){SetStatus(0);}
  if(S==0){SetStatus(100);}
 }
 else{
  if(DigitalRead()){SetStatus(0);}
  else{SetStatus(100);}
 }
}
 void Blink(uint16_t Period,UnitOfTime Unit){
  static VirtualCycleF Bli=VirtualCycleF(Period,Unit);
  for(uint64_t n=Bli.nTick();n>=1;n--){InvertStatus();}
 }
 void FadingLoop(uint8_t MaximumPercentage,uint16_t Period,UnitOfTime Unit){
  TurnOnWithFade(MaximumPercentage,Period,Unit);
  TurnOffWithFade(MaximumPercentage,Period,Unit);
 }
 bool DigitalChanged(){return Change.Changed(DigitalRead());}
};
#endif
