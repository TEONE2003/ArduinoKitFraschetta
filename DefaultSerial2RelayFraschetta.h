#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2RelayFraschetta_h
#define DefaultSerial2RelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2RelayF:DefaultSerial2F,public BasicTerminalRelayF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
 DefaultSerial2RelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,long Baud=9600):BasicTerminalRelayF(Tag,Pin,Type,Save,ReceivedString,Readable),DefaultSerial2F(Baud){}
void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
#endif