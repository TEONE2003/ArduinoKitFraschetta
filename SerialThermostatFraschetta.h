#ifndef SerialThermostatFraschetta_h
#define SerialThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "SerialFraschetta.h"
class SerialThermostatF:public BasicSerialThermostatF,SerialF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
  SerialThermostatF(uint8_t PinRele,String Tag,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString="",uint8_t Rx=2,uint8_t Tx=3,uint32_t Baud=9600):BasicSerialThermostatF(PinRele,Tag,ReleType,TypeT,StatusRequestString),SerialF(Rx,Tx,Baud){}
};
#endif
