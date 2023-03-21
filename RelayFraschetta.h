#ifndef RelayFraschetta_h
#define RelayFraschetta_h
#include "OutputFraschetta.h"
class RelayF:OutputF{
 public:
  RelayF(uint8_t Pin=0,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):OutputF(Pin,Type,Save){}
  void TurnOn(){OutputF::TurnOn();}
  void TurnOff(){OutputF::TurnOff();}
  void InvertStatus(){OutputF::InvertStatus();}
  void Blink(uint16_t Period,UnitOfTime Unit){OutputF::Blink(Period,Unit);}
  bool ReadDigitalStatus(){return OutputF::ReadDigitalStatus();}
};
#endif
