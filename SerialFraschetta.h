#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include "BasicSerialFraschetta.h"
#include "SoftwareSerial.h"
#include "SerialBridgeFraschetta.h"
class SerialF:SoftwareSerial,public BasicSerialF,public SerialBridgeF{
protected:
 boolean DataPresent()override{return available()>0;}
 void SendLn(String S)override{print(S); print("\n");}
 uint8_t SerialRead()override{return read();}
 void SerialWrite(uint8_t B)override{write(B);}
 long Baud;
public:
 SerialF(uint8_t Rx=2,uint8_t Tx=3):SoftwareSerial(Rx,Tx),BasicSerialF(),SerialBridgeF(){Baud=0;}
 void SetBaudRate(long Baud)override{if(Baud!=this->Baud){end(); begin(Baud);} SerialBridgeF::SetBaudRate(Baud);}
 template <typename T> void Send(T t){print(t);}
 template <typename T> void SendLn(T t){print(t); print("\n");}
};
#endif
