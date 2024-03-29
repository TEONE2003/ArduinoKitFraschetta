#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial3ThermostatFraschetta_h
#define DefaultSerial3ThermostatFraschetta_h
#include "BasicTerminalThermostatFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3ThermostatF:public BasicTerminalThermostatF,DefaultSerial3F{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
  DefaultSerial3ThermostatF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):BasicTerminalThermostatF(ReceivedString,Readable,Tag,PinRele,ReleType,TypeT),DefaultSerial3F(){}
void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalThermostatF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
