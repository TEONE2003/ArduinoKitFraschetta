#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial1RelayFraschetta_h
#define DefaultSerial1RelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1RelayF:DefaultSerial1F,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1RelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):BasicTerminalRelayF(ReceivedString,Readable,Tag,Pin,Type,Save),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif