#ifndef Default1BluetoothFraschetta_h
#define Default1BluetoothFraschetta_h
#include "DefaultSerial1Fraschetta.h"
#include "AtCommands.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class Default1BluetoothF:public DefaultSerial1F,public AtCommands{
public:
 Default1BluetoothF(uint32_t Baud=9600):DefaultSerial1F(Baud){}
 void ReceiveString()override{DefaultSerial1F::ReceiveString();}
 String ReadString()override{return DefaultSerial1F::ReadString();}
 void Send(String s)override{DefaultSerial1F::Send(s);}
};
#endif
#endif
