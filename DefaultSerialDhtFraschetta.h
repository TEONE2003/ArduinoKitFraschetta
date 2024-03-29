#ifndef DefaultSerialDhtFraschetta_h
#define DefaultSerialDhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialDhtF:DefaultSerialF,public BasicTerminalDhtF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public: DefaultSerialDhtF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint8_t Type):BasicTerminalDhtF(ReceivedString,Readable,Tag,Pin,Type),DefaultSerialF(){}
void Begin(long Baud=9600){DefaultSerialF::Begin(Baud); BasicTerminalDhtF::Begin();}
};
#endif
