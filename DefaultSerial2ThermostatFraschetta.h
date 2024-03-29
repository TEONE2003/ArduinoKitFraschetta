#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial2ThermostatFraschetta_h
#define DefaultSerial2ThermostatFraschetta_h
#include "BasicTerminalThermostatFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ThermostatF:public BasicTerminalThermostatF,DefaultSerial2F{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
  DefaultSerial2ThermostatF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):BasicTerminalThermostatF(ReceivedString,Readable,Tag,PinRele,ReleType,TypeT),DefaultSerial2F(){}
void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicTerminalThermostatF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif