#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1RelayFraschetta_h
#define DefaultSerial1RelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1RelayF:DefaultSerial1F,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1RelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String *ReceivedString):BasicTerminalRelayF(Tag,Pin,Type,Save,ReceivedString),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
#endif