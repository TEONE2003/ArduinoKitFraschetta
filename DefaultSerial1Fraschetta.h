#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial1Fraschetta_h
#define DefaultSerial1Fraschetta_h
#include "BasicSerialFraschetta.h"
#include "SerialBridgeFraschetta.h"
#include "Serial1BeginFraschetta.h"
class DefaultSerial1F:public BasicSerialF,public SerialBridgeF{
protected:
 boolean DataPresent()override{return Serial1.available()>0;}
 void SendLn(String S)override{Serial1.print(S); Serial1.print("\n");}
 uint8_t SerialRead()override{return Serial1.read();}
 void SerialWrite(uint8_t B)override{Serial1.write(B);}
public:
 DefaultSerial1F():BasicSerialF(),SerialBridgeF(){}
 void SetBaudRate(long Baud)override{Serial1BeginF(Baud); SerialBridgeF::SetBaudRate(Baud);}
 template <typename T> void Send(T t){Serial1.print(t);}
 template <typename T> void SendLn(T t){Serial1.print(t); Serial1.print("\n");}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
