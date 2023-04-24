#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerialF:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial.available()>0;}
 void SerialEnd()override{return Serial.end();}
 void SerialBegin(long Baud)override{return Serial.begin(Baud);}
 uint8_t SerialRead()override{return Serial.read();}
public:
 DefaultSerialF(long Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial.println(t);}
};
#endif
