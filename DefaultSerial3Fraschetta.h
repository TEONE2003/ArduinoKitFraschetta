#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3Fraschetta_h
#define DefaultSerial3Fraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerial3F:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial3.available()>0;}
 void SendLn(String S)override{SendLn(S);}
 void SerialBegin(long Baud)override{Serial3.begin(Baud);}
 uint8_t SerialRead()override{return Serial3.read();}
public:
 DefaultSerial3F(long Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){Serial3.print(t);}
 template <typename T>
 void SendLn(T t){Serial3.print(t); Serial3.print("\n");}
};
#endif
#endif
