#ifndef InputFraschetta_h
#define InputFraschetta_h
enum ResistanceMode{ExternalResistance,PullUp,PullDown};
enum DigitalType:boolean{NormalLogic=1,ReverseLogic=0};
class EntranceF{
 protected:
  uint8_t Pin;
  DigitalType DigitalReadM=NormalLogic;
  ResistanceMode ResistanceM=ResistanceMode::ExternalResistance;
 public:
  void ExternalResistance(){ResistanceM=ResistanceMode::ExternalResistance; PinMode(Pin,INPUT);}
  void PullUp(){ResistanceM=ResistanceMode::PullUp; PinMode(Pin,INPUT_PULLUP);}
  void PullDown(){ResistanceM=ResistanceMode::PullDown; digitalWrite(Pin,0);}
 protected:
  void SetPin(const uint8_t &Pin){this->Pin=Pin; ExternalResistance();}
  void SetResistanceMode(const ResistanceMode &ResistanceM){
   switch(ResistanceM){
    case ResistanceMode::ExternalResistance: ExternalResistance(); break;
    case ResistanceMode::PullUp: PullUp(); break;
    case ResistanceMode::PullDown: PullDown(); break;
   }
  }
  void SetDigitalReadMode(DigitalType &DigitalReadM){
   this->DigitalReadM=DigitalReadM;
  }
 public:
  boolean DigitalRead(){
   boolean L=digitalRead(Pin);
   if(DigitalReadM){return L;}
   else{return !L;}
  }
  uint16_t AnalogRead(){return analogRead(Pin);}
  EntranceF(uint8_t Pin,ResistanceMode ResistanceM=ExternalResistance,DigitalType DigitalReadM=NormalLogic){
   SetResistanceMode(ResistanceM);
   SetDigitalReadMode(DigitalReadM);
   SetPin(Pin);
  }
};
#endif
