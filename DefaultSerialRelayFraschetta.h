#ifndef DefaultSerialRelayFraschetta_h
#define DefaultSerialRelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialRelayF:DefaultSerialF,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelayF(Tag,Pin,Type,Save),DefaultSerialF(Baud){}
};
#endif
