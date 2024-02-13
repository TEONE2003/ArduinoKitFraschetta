#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial3Fraschetta_h
#define DefaultSerial3Fraschetta_h
#include "BasicSerialFraschetta.h"
#include "SerialBridgeFraschetta.h"
#include "Serial3BeginFraschetta.h"
class DefaultSerial3F:public BasicSerialF,public SerialBridgeF{
protected:
 boolean DataPresent()override{return Serial3.available()>0;}
 void SendLn(String S)override{Serial3.print(S); Serial3.print("\n");}
 uint8_t SerialRead()override{return Serial3.read();}
 void SerialWrite(uint8_t B)override{Serial3.write(B);}
public:
 DefaultSerial3F():BasicSerialF(),SerialBridgeF(){}
 void SetBaudRate(long Baud)override{Serial3BeginF(Baud); SerialBridgeF::SetBaudRate(Baud);}
 template <typename T>
 void Send(T t){Serial3.print(t);}
 template <typename T>
 void SendLn(T t){Serial3.print(t); Serial3.print("\n");}
};
#endif
#endif
