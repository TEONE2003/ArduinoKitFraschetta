#ifndef DefaultSerialThermostatFraschetta_h
#define DefaultSerialThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialThermostatF:public BasicSerialThermostatF,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
  DefaultSerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,uint32_t Baud=9600):BasicSerialThermostatF(Tag,PinRele,ReleType,TypeT),DefaultSerialF(Baud){}
};
#endif
