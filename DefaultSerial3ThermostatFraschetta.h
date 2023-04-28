#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3ThermostatFraschetta_h
#define DefaultSerial3ThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3ThermostatF:public BasicSerialThermostatF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
  DefaultSerial3ThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,uint32_t Baud=9600):BasicSerialThermostatF(Tag,PinRele,ReleType,TypeT),DefaultSerial3F(Baud){}
void Begin(){DefaultSerial3F::Begin(); BasicSerialThermostatF::Begin();}
};
#endif
#endif
