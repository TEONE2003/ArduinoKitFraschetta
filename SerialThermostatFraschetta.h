#ifndef SerialThermostatFraschetta_h
#define SerialThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "SerialFraschetta.h"
class SerialThermostatF:public BasicSerialThermostatF,SerialF{
 public:
  SerialThermostatF(){}
  SerialThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint32_t Baud=9600):BasicSerialThermostatF(PinRele,ReleType,TypeT,StatusRequestString):SerialF(RX,TX,Baud){}
  void Send(String s)override{SerialF:Send(s);}
};
#endif
