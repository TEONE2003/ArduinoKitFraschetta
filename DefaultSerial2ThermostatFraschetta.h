#ifndef DefaultSerial2ThermostatFraschetta_h
#define DefaultSerial2ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ThermostatF:public BasicSerialThermostatF,DefaultSerial2F{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
  DefaultSerial2ThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,uint32_t Baud=9600):BasicSerialThermostatF(Tag,PinRele,ReleType,TypeT),DefaultSerial2F(Baud){}
};
#endif
