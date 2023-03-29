#ifndef DefaultSerial3DhtFraschetta_h
#define DefaultSerial3DhtFraschetta_h
#include "BasicSerialDhtFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3DhtF:DefaultSerial3F,public BasicSerialDhtF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public: DefaultSerial3DhtF(String Tag,uint8_t Pin,uint8_t Type,uint32_t Baud=9600):BasicSerialDhtF(Tag,Pin,Type),DefaultSerial3F(Baud){}
};
#endif
