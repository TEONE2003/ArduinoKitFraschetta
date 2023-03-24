#ifndef DefaultSerial1ThermostatFraschetta_h
#define DefaultSerial1ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1ThermostatF:public BasicSerialThermostatF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F:SendLn(s);}
public:
  DefaultSerial1ThermostatF(){}
  DefaultSerial1ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint32_t Baud=9600):BasicSerialThermostatF(PinRele,ReleType,TypeT,StatusRequestString):DefaultSerial1F(Baud){}
};
#endif
