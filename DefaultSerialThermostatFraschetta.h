#ifndef DefaultSerialThermostatFraschetta_h
#define DefaultSerialThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialThermostatF:public BasicSerialThermostatF,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF:SendLn(s);}
public:
  DefaultSerialThermostatF(){}
  DefaultSerialThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint32_t Baud=9600):BasicSerialThermostatF(PinRele,ReleType,TypeT,StatusRequestString),DefaultSerialF(Baud){}
};
#endif
