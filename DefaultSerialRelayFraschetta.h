#ifndef DefaultSerialRelayFraschetta_h
#define DefaultSerialRelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialRelayF:DefaultSerialF,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String *ReceivedString):BasicSerialRelayF(Tag,Pin,Type,Save,ReceivedString),DefaultSerialF(){}
 void Begin(long Baud=9600){DefaultSerialF::SetBaudRate(Baud); BasicSerialRelayF::Begin();}
};
#endif
