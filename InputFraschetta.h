#ifndef InputFraschetta_h
#define InputFraschetta_h
#include "DigitalTypeFraschetta.h"
enum ResistanceMode{ExternalResistance,PullUp,PullDown};
class InputF{
 protected:
  uint8_t Pin;
  DigitalType DigitalReadM=NormalLogic;
  ResistanceMode ResistanceM=ResistanceMode::ExternalResistance;
 public:
  void SetExternalResistance(){ResistanceM=ResistanceMode::ExternalResistance; pinMode(Pin,INPUT);}
  void SetPullUp(){ResistanceM=ResistanceMode::PullUp; pinMode(Pin,INPUT_PULLUP);}
  void SetPullDown(){ResistanceM=ResistanceMode::PullDown; digitalWrite(Pin,0);}
 protected:
  void SetPin(uint8_t Pin){this->Pin=Pin; SetExternalResistance();}
  void SetResistanceMode(ResistanceMode ResistanceM){
   switch(ResistanceM){
    case ResistanceMode::ExternalResistance: SetExternalResistance(); break;
    case ResistanceMode::PullUp: SetPullUp(); break;
    case ResistanceMode::PullDown: SetPullDown(); break;
   }
  }
  void SetDigitalReadMode(DigitalType DigitalReadM){
   this->DigitalReadM=DigitalReadM;
  }
 public:
  boolean DigitalRead(){
   boolean L=digitalRead(Pin);
   if(DigitalReadM){return L;}
   else{return !L;}
  }
  uint16_t AnalogRead(){return analogRead(Pin);}
  InputF(uint8_t Pin=0,ResistanceMode ResistanceM=ExternalResistance,DigitalType DigitalReadM=NormalLogic){
   SetResistanceMode(ResistanceM);
   SetDigitalReadMode(DigitalReadM);
   SetPin(Pin);
  }
};
#endif
