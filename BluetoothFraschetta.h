#ifndef BluetoothFraschetta_h
#define BluetoothFraschetta_h
#include "SerialFraschetta.h"
#include "AtCommandsFraschetta.h"
class BluetoothF:public SerialF,public AtCommandsF{
public:
 BluetoothF(uint8_t Rx=2,uint8_t Tx=3,uint32_t Baud=9600):SerialF( Rx,Tx,Baud){}
 void ReceiveString()override{SerialF::ReceiveString();}
 String ReadString()override{return SerialF::ReadString();}
 void Send(String s)override{SerialF::Send(s);}
 template <typename T>
 void Send(T t){SerialF::Send(t);}
};
#endif
