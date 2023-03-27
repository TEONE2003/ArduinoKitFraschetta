#ifndef DefaultSerial1PhotocellDuskToDawnFraschetta_h
#define DefaultSerial1PhotocellDuskToDawnFraschetta_h
#include "BasicSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1PhotocellDuskToDawnF:public BasicSerial1PhotocellDuskToDawnF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1PhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,uint16_t Baud=9600):BasicSerial1PhotocellDuskToDawnF(Tag,StatusRequestString,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial1F(Baud){}
};
#endif
