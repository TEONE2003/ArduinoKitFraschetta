#ifndef DefaultSerialThermostatFraschetta_h
#define DefaultSerialThermostatFraschetta_h
#include "BasicTerminalThermostatFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialThermostatF:public BasicTerminalThermostatF,DefaultSerialF{
protected: void Send(String s)override{DefaultSerialF::SendLn(s);}
public:
  DefaultSerialThermostatF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):BasicTerminalThermostatF(ReceivedString,Readable,Tag,PinRele,ReleType,TypeT),DefaultSerialF(){}
 void Begin(long Baud=9600){DefaultSerialF::SetBaudRate(Baud); BasicTerminalThermostatF::Begin();}
};
#endif
