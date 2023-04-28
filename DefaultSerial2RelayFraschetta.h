#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2RelayFraschetta_h
#define DefaultSerial2RelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2RelayF:DefaultSerial2F,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
 DefaultSerial2RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,long Baud=9600):BasicSerialRelayF(Tag,Pin,Type,Save),DefaultSerial2F(Baud){}
void Begin(){DefaultSerial2F::Begin(); BasicSerialRelayF::Begin();}
};
#endif
#endif