#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2Fraschetta_h
#define DefaultSerial2Fraschetta_h
#include "BasicSerialFraschetta.h"
class DefaultSerial2F:public BasicSerialF{
protected:
 boolean DataPresent()override{return Serial2.available()>0;}
 void SendLn(String S)override{SendLn(S);}
 void SerialBegin(long Baud)override{Serial2.begin(Baud);}
 uint8_t SerialRead()override{return Serial2.read();}
public:
 DefaultSerial2F(long Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){Serial2.print(t);}
 template <typename T>
 void SendLn(T t){Serial2.print(t); Serial2.print("\n");}
};
#endif
#endif
