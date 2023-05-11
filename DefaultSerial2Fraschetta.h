#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2Fraschetta_h
#define DefaultSerial2Fraschetta_h
#include "BasicSerialFraschetta.h"
#include "SerialBridgeFraschetta.h"
#include "ExecuteOnceFraschetta.h"
class DefaultSerial2F:public BasicSerialF,public SerialBridgeF{
protected:
 boolean DataPresent()override{return Serial2.available()>0;}
 void SendLn(String S)override{Serial2.print(S); Serial2.print("\n");}
 uint8_t SerialRead()override{return Serial2.read();}
 void SerialWrite(uint8_t B)override{Serial2.write(B);}
public:
 DefaultSerial2F(long Baud=9600):BasicSerialF(Baud),SerialBridgeF(Baud){}
 void Begin()override{static ExecuteOnceF IS=ExecuteOnceF(); if(IS.NoExecuted()){Serial2.end(); Serial2.begin(BasicSerialF::Baud);}}
 template <typename T>
 void Send(T t){Serial2.print(t);}
 template <typename T>
 void SendLn(T t){Serial2.print(t); Serial2.print("\n");}
};
#endif
#endif
