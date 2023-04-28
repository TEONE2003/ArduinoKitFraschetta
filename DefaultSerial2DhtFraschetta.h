#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2DhtFraschetta_h
#define DefaultSerial2DhtFraschetta_h
#include "BasicSerialDhtFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2DhtF:DefaultSerial2F,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public: DefaultSerial2DhtF(String Tag,uint8_t Pin,uint8_t Type,uint32_t Baud=9600):BasicSerialDhtF(Tag,Pin,Type),DefaultSerial2F(Baud){}
void Begin(){DefaultSerial2F::Begin(); BasicSerialDhtF::Begin();}
};
#endif
#endif
