#ifndef RelayFraschetta_h
#define RelayFraschetta_h
#include "OutputFraschetta.h"
class RelayF:OutputF{
 public:
  RelayF(){}
  RelayF(uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):OutputF(Pin,Type,Save){}
    using OutputF::Begin; using OutputF::TurnOn; using OutputF::TurnOff; using OutputF::InvertStatus; using OutputF::Blink; using OutputF::ReadDigitalStatus;
};
#endif
