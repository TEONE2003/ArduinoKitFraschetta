#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerialF:public BasicSerialF{
protected:
 bool DataPresent()override{return Serial.available()>0;}
 void SendLn(String S)override{Serial.print(S); Serial.print("\n");}
 uint8_t SerialRead()override{return Serial.read();}
public:
 DefaultSerialF(long Baud=9600):BasicSerialF(Baud){}
 void Begin()override{static bool Begin=0; if(!Begin){Serial.end(); Serial.begin(BasicSerialF::Baud);}}
 template <typename T>
 void Send(T t){Serial.print(t);}
 template <typename T>
 void SendLn(T t){Serial.print(t); Serial.print("\n");}
};
#endif
