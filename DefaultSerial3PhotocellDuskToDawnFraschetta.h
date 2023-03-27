#ifndef DefaultSerial3PhotocellDuskToDawnFraschetta_h
#define DefaultSerial3PhotocellDuskToDawnFraschetta_h
#include "BasicSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3PhotocellDuskToDawnF:public BasicSerial3PhotocellDuskToDawnF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
 DefaultSerial3PhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,uint16_t Baud=9600):BasicSerial3PhotocellDuskToDawnF(Tag,StatusRequestString,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial3F(Baud){}
};
#endif
