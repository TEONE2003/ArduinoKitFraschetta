#ifndef Default2BluetoothFraschetta_h
#define Default2BluetoothFraschetta_h
#include "DefaultSerial2Fraschetta.h"
#include "AtCommands.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class Default2BluetoothF:public DefaultSerial2F,public AtCommands{
public:
 Default2BluetoothF(uint32_t Baud=9600):DefaultSerial2F(Baud){}
 void ReceiveString()override{DefaultSerial2F::ReceiveString();}
 String ReadString()override{return DefaultSerial2F::ReadString();}
 void Send(String s)override{DefaultSerial2F::Send(s);}
};
#endif
#endif
