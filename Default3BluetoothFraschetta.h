#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef Default3BluetoothFraschetta_h
#define Default3BluetoothFraschetta_h
#include "DefaultSerialFraschetta.h"
#include "AtCommandsFraschetta.h"
class Default3BluetoothF:public DefaultSerial3F,public AtCommandsF{
public:
 Default3BluetoothF():DefaultSerial3F(){}
 void ReceiveString()override{DefaultSerial3F::ReceiveString();}
 String ReadString()override{return DefaultSerial3F::ReadString();}
 void Send(String s)override{DefaultSerial3F::Send(s);}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
