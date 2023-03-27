#ifndef DefaultSerialPhotocellDuskToDawnFraschetta_h
#define DefaultSerialPhotocellDuskToDawnFraschetta_h
#include "BasicSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialPhotocellDuskToDawnF:public BasicSerialPhotocellDuskToDawnF,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialPhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,uint16_t Baud=9600):BasicSerialPhotocellDuskToDawnF(Tag,StatusRequestString,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerialF(Baud){}
};
#endif
