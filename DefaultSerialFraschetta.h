#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerialF:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial.end(); Serial.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial.available()>0;}
 String string()override{return Serial.readString();}
 uint8_t Byte()override{return Serial.read();}
 char Char()override{return Serial.read();}
public:
 DefaultSerialF(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial.println(t);}
};
#endif
