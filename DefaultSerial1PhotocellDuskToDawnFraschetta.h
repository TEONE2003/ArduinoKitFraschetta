#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1PhotocellDuskToDawnFraschetta_h
#define DefaultSerial1PhotocellDuskToDawnFraschetta_h
#include "BasicTerminalPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1PhotocellDuskToDawnF:public BasicTerminalPhotocellDuskToDawnF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1PhotocellDuskToDawnF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType):BasicTerminalPhotocellDuskToDawnF(ReceivedString,Readable,Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalPhotocellDuskToDawnF::Begin();}
};
#endif
#endif
