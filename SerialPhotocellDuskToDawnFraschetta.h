#ifndef SerialPhotocellDuskToDawnFraschetta_h
#define SerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "SerialFraschetta.h"
class SerialPhotocellDuskToDawnF:public PhotocellDuskToDawnFraschetta,SerialF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
 SerialPhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType,uint8_t RX=2,uint8_t TX=3,uint32_t Baud=9600):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),SerialF(RX,TX,Baud){}
};
#endif
