#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1ThermostatFraschetta_h
#define DefaultSerial1ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1ThermostatF:public BasicSerialThermostatF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
  DefaultSerial1ThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,uint32_t Baud=9600):BasicSerialThermostatF(Tag,PinRele,ReleType,TypeT),DefaultSerial1F(Baud){}
void Begin(){DefaultSerial1F::Begin(); BasicSerialThermostatF::Begin();}
};
#endif
#endif