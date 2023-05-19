#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include "BasicSerialFraschetta.h"
#include "SerialBeginFraschetta.h"
class DefaultSerialF:public BasicSerialF{
protected:
 bool DataPresent()override{return Serial.available()>0;}
 void SendLn(String S)override{Serial.print(S); Serial.print("\n");}
 uint8_t SerialRead()override{return Serial.read();}
public:
 DefaultSerialF():BasicSerialF(){}
 void SetBaudRate(long Baud)override{SerialBeginF(Baud);}
 template <typename T> void Send(T t){Serial.print(t);}
 template <typename T> void SendLn(T t){Serial.print(t); Serial.print("\n");}
};
#endif
