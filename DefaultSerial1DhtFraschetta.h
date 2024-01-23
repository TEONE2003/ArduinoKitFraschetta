#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1DhtFraschetta_h
#define DefaultSerial1DhtFraschetta_h
#include "BasicSerialDhtFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1DhtF:DefaultSerial1F,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public: DefaultSerial1DhtF(String Tag,uint8_t Pin,uint8_t Type,String *ReceivedString):BasicSerialDhtF(Tag,Pin,Type,ReceivedString),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicSerialDhtF::Begin();}
};
#endif
#endif
