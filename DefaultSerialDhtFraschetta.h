#ifndef DefaultSerialDhtFraschetta_h
#define DefaultSerialDhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialDhtF:DefaultSerialF,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public: DefaultSerialDhtF(String Tag,uint8_t Pin,uint8_t Type,String *ReceivedString,bool *Readable):BasicSerialDhtF(Tag,Pin,Type,ReceivedString,Readable),DefaultSerialF(){}
void Begin(long Baud=9600){DefaultSerialF::Begin(Baud); BasicSerialDhtF::Begin();}
};
#endif
