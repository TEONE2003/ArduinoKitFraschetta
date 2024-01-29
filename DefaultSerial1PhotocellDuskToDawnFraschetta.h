#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1PhotocellDuskToDawnFraschetta_h
#define DefaultSerial1PhotocellDuskToDawnFraschetta_h
#include "BasicTerminalPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1PhotocellDuskToDawnF:public BasicTerminalPhotocellDuskToDawnF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1PhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,String *ReceivedString,bool *Readable):BasicTerminalPhotocellDuskToDawnF(Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType,ReceivedString,Readable),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalPhotocellDuskToDawnF::Begin();}
};
#endif
#endif
