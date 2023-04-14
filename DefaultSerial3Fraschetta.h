#ifndef DefaultSerial3Fraschetta_h
#define DefaultSerial3Fraschetta_h
#include "BasicSerialFraschetta.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial3F:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial3.available()>0;}
 void SerialEnd()override{return Serial3.end();}
 uint8_t SerialBegin(long Baud)override{return Serial3.begin(Baud);}
 uint8_t SerialRead()override{return Serial3.read();}
public:
 DefaultSerial3F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial3.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial3.println(t);}
};
#endif
#endif
