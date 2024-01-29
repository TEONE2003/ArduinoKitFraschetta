#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3RelayFraschetta_h
#define DefaultSerial3RelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3RelayF:DefaultSerial3F,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String *ReceivedString):BasicTerminalRelayF(Tag,Pin,Type,Save,ReceivedString),DefaultSerial3F(){}
void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
#endif