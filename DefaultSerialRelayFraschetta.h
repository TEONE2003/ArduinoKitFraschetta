#ifndef DefaultSerialRelayFraschetta_h
#define DefaultSerialRelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialRelayF:DefaultSerialF,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialRelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):BasicTerminalRelayF(Tag,Pin,Type,Save,ReceivedString,Readable),DefaultSerialF(){}
 void Begin(long Baud=9600){DefaultSerialF::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
