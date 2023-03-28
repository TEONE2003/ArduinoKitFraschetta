#ifndef DefaultSerial2RelayFraschetta_h
#define DefaultSerial2RelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2RelayF:DefaultSerial2F,public BasicSerial2RelayF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
 DefaultSerial2RelayF(){}
 DefaultSerial2RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelayF(Tag,Pin,Type,Save),DefaultSerial2F(Baud){}
};
#endif
