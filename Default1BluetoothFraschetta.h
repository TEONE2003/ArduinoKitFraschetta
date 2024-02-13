#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef Default1BluetoothFraschetta_h
#define Default1BluetoothFraschetta_h
#include "DefaultSerial1Fraschetta.h"
#include "AtCommandsFraschetta.h"
class Default1BluetoothF:public DefaultSerial1F,public AtCommandsF{
public:
 Default1BluetoothF():DefaultSerial1F(){}
void ReceiveString()override{DefaultSerial1F::ReceiveString();}
 String ReadString()override{return DefaultSerial1F::ReadString();}
 void Send(String s)override{DefaultSerial1F::Send(s);}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
