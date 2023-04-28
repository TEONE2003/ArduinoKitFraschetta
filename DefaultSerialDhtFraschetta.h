#ifndef DefaultSerialDhtFraschetta_h
#define DefaultSerialDhtFraschetta_h
#include "BasicSerialDhtFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialDhtF:DefaultSerialF,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public: DefaultSerialDhtF(String Tag,uint8_t Pin,uint8_t Type,uint32_t Baud=9600):BasicSerialDhtF(Tag,Pin,Type),DefaultSerialF(Baud){}
void Begin(){DefaultSerialF::Begin(); BasicSerialDhtF::Begin();}
};
#endif
