#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3RelayFraschetta_h
#define DefaultSerial3RelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3RelayF:DefaultSerial3F,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelayF(Tag,Pin,Type,Save),DefaultSerial3F(Baud){}
void Begin(){DefaultSerial3F::Begin(); BasicSerialRelayF::Begin();}
};
#endif
#endif