#ifndef DefaultBluetoothFraschetta_h
#define DefaultBluetoothFraschetta_h
#include "DefaultSerialFraschetta.h"
#include "AtCommandsFraschetta.h"
class DefaultBluetoothF:public DefaultSerialF,public AtCommandsF{
public:
 DefaultBluetoothF(long Baud=9600):DefaultSerialF(Baud){}
 void ReceiveString()override{DefaultSerialF::ReceiveString();}
 String ReadString()override{return DefaultSerialF::ReadString();}
 void Send(String s)override{DefaultSerialF::Send(s);}
 template <typename T>
 void Send(T t){DefaultSerialF::Send(t);}
};
#endif
