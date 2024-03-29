#ifndef DefaultSerialPhotocellDuskToDawnFraschetta_h
#define DefaultSerialPhotocellDuskToDawnFraschetta_h
#include "BasicTerminalPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialPhotocellDuskToDawnF:public BasicTerminalPhotocellDuskToDawnF,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialPhotocellDuskToDawnF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType):BasicTerminalPhotocellDuskToDawnF(ReceivedString,Readable,Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerialF(){}
 void Begin(long Baud=9600){DefaultSerialF::SetBaudRate(Baud); BasicTerminalPhotocellDuskToDawnF::Begin();}
};
#endif
