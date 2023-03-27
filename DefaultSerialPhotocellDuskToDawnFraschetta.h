#ifndef DefaultSerialPhotocellDuskToDawnFraschetta_h
#define DefaultSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialPhotocellDuskToDawnF:public PhotocellDuskToDawnFraschetta,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerialPhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType,uint32_t Baud=9600):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerialF(Baud){}
};
#endif
