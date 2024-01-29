#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "BasicTerminalRelayFraschetta.h"
#include "SerialFraschetta.h"
class SerialRelayF:SerialF,public BasicTerminalRelayF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public: SerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint8_t Rx=2,uint8_t Tx=3,String *ReceivedString,bool *Readable):BasicTerminalRelayF(Tag,Pin,Type,Save,ReceivedString,Readable),SerialF(Rx,Tx){}
void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicTerminalRelayF::Begin();}
};
#endif
