#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3DhtFraschetta_h
#define DefaultSerial3DhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3DhtF:DefaultSerial3F,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public: DefaultSerial3DhtF(String Tag,uint8_t Pin,uint8_t Type,String *ReceivedString):BasicSerialDhtF(Tag,Pin,Type,ReceivedString),DefaultSerial3F(){}
void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicSerialDhtF::Begin();}
};
#endif
#endif
