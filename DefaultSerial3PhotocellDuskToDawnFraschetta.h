#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3PhotocellDuskToDawnFraschetta_h
#define DefaultSerial3PhotocellDuskToDawnFraschetta_h
#include "BasicSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3PhotocellDuskToDawnF:public BasicSerialPhotocellDuskToDawnF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3PhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType):BasicSerialPhotocellDuskToDawnF(Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial3F(){}
 void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicSerialPhotocellDuskToDawnF::Begin();}
};
#endif
#endif
