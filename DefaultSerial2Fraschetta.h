#ifndef DefaultSerial2Fraschetta_h
#define DefaultSerial2Fraschetta_h
#include "BasicSerialFraschetta.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial2F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial2.end(); Serial2.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial2.available()>0;}
 String string()override{return Serial2.readString();}
 uint8_t Byte()override{return Serial2.read();}
 char Char()override{return Serial2.read();}
public:
 DefaultSerial2F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial2.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial2.println(t);}
};
#endif
#endif
