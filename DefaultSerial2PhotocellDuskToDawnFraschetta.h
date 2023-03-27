#ifndef DefaultSerial2PhotocellDuskToDawnFraschetta_h
#define DefaultSerial2PhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2PhotocellDuskToDawnF:public PhotocellDuskToDawnFraschetta,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
 DefaultSerial2PhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType,uint32_t Baud=9600):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),DefaultSerial2F(Baud){}
};
#endif
