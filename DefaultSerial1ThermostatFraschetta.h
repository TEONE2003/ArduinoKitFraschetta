#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1ThermostatFraschetta_h
#define DefaultSerial1ThermostatFraschetta_h
#include "BasicTerminalThermostatFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1ThermostatF:public BasicTerminalThermostatF,DefaultSerial1F{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
  DefaultSerial1ThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String *ReceivedString,bool *Readable):BasicTerminalThermostatF(Tag,PinRele,ReleType,TypeT,ReceivedString,Readable),DefaultSerial1F(){}
void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalThermostatF::Begin();}
};
#endif
#endif