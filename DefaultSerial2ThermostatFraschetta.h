#ifndef DefaultSerial2ThermostatFraschetta_h
#define DefaultSerial2ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ThermostatF:public BasicSerialThermostatF,DefaultSerial2F{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
  DefaultSerial2ThermostatF(){}
  DefaultSerial2ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint32_t Baud=9600):BasicSerialThermostatF(PinRele,ReleType,TypeT,StatusRequestString),DefaultSerial2F(Baud){}
};
#endif
