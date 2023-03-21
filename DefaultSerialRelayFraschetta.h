#ifndef DefaultSerialRelayFraschetta_h
#define DefaultSerialRelayFraschetta_h
#include "BasicSerialRelay.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialRelayF:DefaultSerialF,public BasicSerialRelay{
public:
 DefaultSerialRelayF(){}
 DefaultSerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save,StatusRequestString):DefaultSerialF(Baud){}
 void Send(String s)override{DefaultSerialF:Send(s);}
};
#endif
