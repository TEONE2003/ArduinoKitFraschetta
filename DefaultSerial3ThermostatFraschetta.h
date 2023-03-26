#ifndef DefaultSerial3ThermostatFraschetta_h
#define DefaultSerial3ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3ThermostatF:public BasicSerialThermostatF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
  DefaultSerial3ThermostatF(){}
  DefaultSerial3ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint32_t Baud=9600):BasicSerialThermostatF(PinRele,ReleType,TypeT,StatusRequestString),DefaultSerial3F(Baud){}
};
#endif
