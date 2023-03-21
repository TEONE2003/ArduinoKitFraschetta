#ifndef DefaultSerial3Fraschetta_h
#define DefaultSerial3Fraschetta_h
#include "BasicSerialFraschetta.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial3F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial3.end(); Serial3.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial3.available()>0;}
 String string()override{return Serial3.readString();}
 uint8_t Byte()override{return Serial3.read();}
 char Char()override{return Serial3.read();}
public:
 DefaultSerial3F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial3.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial3.println(t);}
};
#endif
#endif
