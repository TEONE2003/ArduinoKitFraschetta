#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial2DhtFraschetta_h
#define DefaultSerial2DhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2DhtF:DefaultSerial2F,public BasicTerminalDhtF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public: DefaultSerial2DhtF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint8_t Type):BasicTerminalDhtF(ReceivedString,Readable,Tag,Pin,Type),DefaultSerial2F(){}
void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicTerminalDhtF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
