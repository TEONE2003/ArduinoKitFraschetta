#ifndef SerialThermostatFraschetta_h
#define SerialThermostatFraschetta_h
#include "BasicSerialThermostatFraschetta.h"
#include "SerialFraschetta.h"
class SerialThermostatF:public BasicSerialThermostatF,SerialF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
 SerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,uint8_t Rx=2,uint8_t Tx=3):BasicSerialThermostatF(Tag,PinRele,ReleType,TypeT),SerialF(Rx,Tx){}
 void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicSerialThermostatF::Begin();}
};
#endif
