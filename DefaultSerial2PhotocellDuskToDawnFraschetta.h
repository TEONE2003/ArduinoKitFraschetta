#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2PhotocellDuskToDawnFraschetta_h
#define DefaultSerial2PhotocellDuskToDawnFraschetta_h
#include "BasicSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2PhotocellDuskToDawnF:public BasicSerialPhotocellDuskToDawnF,DefaultSerial2F{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
 DefaultSerial2PhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,String *ReceivedString):BasicSerialPhotocellDuskToDawnF(Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType,ReceivedString),DefaultSerial2F(){}
void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicSerialPhotocellDuskToDawnF::Begin();}
};
#endif
#endif
