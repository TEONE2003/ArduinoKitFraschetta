#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial3RelayFraschetta_h
#define DefaultSerial3RelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3RelayF:DefaultSerial3F,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3RelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):BasicTerminalRelayF(ReceivedString,Readable,Tag,Pin,Type,Save),DefaultSerial3F(){}
void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
#endif