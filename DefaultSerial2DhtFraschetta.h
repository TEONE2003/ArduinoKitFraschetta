#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2DhtFraschetta_h
#define DefaultSerial2DhtFraschetta_h
#include "BasicSerialDhtFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2DhtF:DefaultSerial2F,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public: DefaultSerial2DhtF(String Tag,uint8_t Pin,uint8_t Type,String *ReceivedString):BasicSerialDhtF(Tag,Pin,Type,ReceivedString),DefaultSerial2F(){}
void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicSerialDhtF::Begin();}
};
#endif
#endif
