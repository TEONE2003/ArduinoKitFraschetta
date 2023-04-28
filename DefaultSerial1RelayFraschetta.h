#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1RelayFraschetta_h
#define DefaultSerial1RelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1RelayF:DefaultSerial1F,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelayF(Tag,Pin,Type,Save),DefaultSerial1F(Baud){}
void Begin(){DefaultSerial1F::Begin(); BasicSerialRelayF::Begin();}
};
#endif
#endif