#ifndef InputFraschetta_h
#define InputFraschetta_h
#include "DigitalTypeFraschetta.h"
#include "CheckChangeFraschetta.h"
enum ResistanceMode{ExternalResistance,PullUp,PullDown};
class InputF{
 protected:
  uint8_t Pin;
  DigitalType DigitalReadM=NormalLogic;
  ResistanceMode ResistanceM=ResistanceMode::ExternalResistance;
  CheckChangeF<bool>Change;
 public:
  void SetExternalResistance(){ResistanceM=ResistanceMode::ExternalResistance; pinMode(Pin,INPUT);}
  void SetPullUp(){ResistanceM=ResistanceMode::PullUp; pinMode(Pin,INPUT_PULLUP);}
  void SetPullDown(){ResistanceM=ResistanceMode::PullDown; pinMode(Pin,INPUT_PULLUP);}
  void SetResistanceMode(ResistanceMode ResistanceType){
   switch(ResistanceType){
    case ResistanceMode::ExternalResistance: SetExternalResistance(); break;
    case ResistanceMode::PullUp: SetPullUp(); break;
    case ResistanceMode::PullDown: SetPullDown(); break;
   }
  }
  void SetDigitalReadMode(DigitalType DigitalReadM){this->DigitalReadM=DigitalReadM;}
  bool DigitalRead(){
   boolean R=digitalRead(Pin);
   if((DigitalReadM && (ResistanceM==ExternalResistance || ResistanceM==PullUp)) ||  !DigitalReadM && ResistanceM==PullDown){return R;}
   else{return !R;}
  }
  void Begin(){pinMode(Pin,INPUT); SetResistanceMode(ResistanceM); Change=CheckChangeF<bool>(DigitalRead());}
  uint16_t AnalogRead(){return analogRead(Pin);}
   bool DigitalChanged(){return Change.Changed(DigitalRead());}
   InputF(uint8_t Pin=0,ResistanceMode ResistanceM=ExternalResistance,DigitalType DigitalReadM=NormalLogic){
   SetResistanceMode(ResistanceM); SetDigitalReadMode(DigitalReadM); this->Pin=Pin; Change=CheckChangeF<bool>(false);
  }
};
#endif
