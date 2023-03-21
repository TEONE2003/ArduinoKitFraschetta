#ifndef DefaultSerial1Fraschetta_h
#define DefaultSerial1Fraschetta_h
#include "BasicSerialFraschetta.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial1F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial1.end(); Serial1.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial1.available()>0;}
 String string()override{return Serial1.readString();}
 uint8_t Byte()override{return Serial1.read();}
 char Char()override{return Serial1.read();}
public:
 DefaultSerial1F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial1.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial1.println(t);}
};
#endif
#endif
