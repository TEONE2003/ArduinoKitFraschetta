#ifndef DefaultSerial1Fraschetta_h
#define DefaultSerial1Fraschetta_h
#include "BasicSerialFraschetta.h"
#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial1F:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial1.available()>0;}
 void SerialEnd()override{return Serial1.end();}
 uint8_t SerialBegin(long Baud)override{return Serial1.begin(Baud);}
 uint8_t SerialRead()override{return Serial1.read();}
public:
 DefaultSerial1F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial1.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial1.println(t);}
};
#endif
#endif
