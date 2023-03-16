#ifndef ReleFraschetta_h
#define ReleFraschetta_h
#include <OutputFraschetta.h>
class Rele:OutputF{
 public:
  Rele(uint8_t Pin=0,DigitalType Type=NormalLogic,MemorizeStatus Save=SaveStatus):OutputF(Pin,Type,Save){}
  void TurnOn(){OutputF::TurnOn();}
  void TurnOff(){OutputF::TurnOff();}
  void InvertStatus(){OutputF::InvertStatus();}
  void Blink(uint16_t Period,UnitOfTime Unit){OutputF::Blink(Period,Unit);}
};
#endif
