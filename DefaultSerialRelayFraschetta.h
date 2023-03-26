#ifndef DefaultSerialRelayFraschetta_h
#define DefaultSerialRelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialRelayF:DefaultSerialF,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialRelayF(){}
 DefaultSerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelayF(Pin,Tag,Type,Save,StatusRequestString),DefaultSerialF(Baud){}
};
#endif
