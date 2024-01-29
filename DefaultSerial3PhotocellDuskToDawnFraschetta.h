#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3PhotocellDuskToDawnFraschetta_h
#define DefaultSerial3PhotocellDuskToDawnFraschetta_h
#include "BasicTerminalPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3PhotocellDuskToDawnF:public BasicTerminalPhotocellDuskToDawnF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3PhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,String *ReceivedString,bool *Readable):BasicTerminalPhotocellDuskToDawnF(Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType,ReceivedString,Readable),DefaultSerial3F(){}
 void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalPhotocellDuskToDawnF::Begin();}
};
#endif
#endif
