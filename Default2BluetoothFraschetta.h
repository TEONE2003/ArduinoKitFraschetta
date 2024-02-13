#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef Default2BluetoothFraschetta_h
#define Default2BluetoothFraschetta_h
#include "DefaultSerial2Fraschetta.h"
#include "AtCommandsFraschetta.h"
class Default2BluetoothF:public DefaultSerial2F,public AtCommandsF{
public:
 Default2BluetoothF():DefaultSerial2F(){}
 void ReceiveString()override{DefaultSerial2F::ReceiveString();}
 String ReadString()override{return DefaultSerial2F::ReadString();}
 void Send(String s)override{DefaultSerial2F::Send(s);}
};
#endif
#endif
