#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial3DhtFraschetta_h
#define DefaultSerial3DhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3DhtF:DefaultSerial3F,public BasicTerminalDhtF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public: DefaultSerial3DhtF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint8_t Type):BasicTerminalDhtF(ReceivedString,Readable,Tag,Pin,Type),DefaultSerial3F(){}
void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalDhtF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
