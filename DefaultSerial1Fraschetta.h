#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1Fraschetta_h
#define DefaultSerial1Fraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerial1F:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial1.available()>0;}
 void SendLn(String S)override{SendLn(S);}
 void SerialBegin(long Baud)override{Serial1.begin(Baud);}
 uint8_t SerialRead()override{return Serial1.read();}
public:
 DefaultSerial1F(long Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){Serial1.print(t);}
 template <typename T>
 void SendLn(T t){Serial1.print(t); Serial1.print("\n");}
};
#endif
#endif
