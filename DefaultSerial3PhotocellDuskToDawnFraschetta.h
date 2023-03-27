#ifndef DefaultSerial3PhotocellDuskToDawnFraschetta_h
#define DefaultSerial3PhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial3PhotocellDuskToDawnF:public PhotocellDuskToDawnFraschetta,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerial3PhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType,uint32_t Baud=9600):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial3F(Baud){}
};
#endif
