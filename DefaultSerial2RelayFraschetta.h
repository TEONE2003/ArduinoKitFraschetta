#ifndef DefaultSerial2RelayF_h
#define DefaultSerial2RelayF_h
#include "BasicSerialRelay.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2RelayF:DefaultSerial2F,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerial2F:SendLn(s);}
public:
 DefaultSerial1RelayF(){}
 DefaultSerial1RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save,StatusRequestString),DefaultSerial2F(Baud){}
};
#endif
