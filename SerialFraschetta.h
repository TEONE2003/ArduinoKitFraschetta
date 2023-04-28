#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include "BasicSerialFraschetta.h"
#include "SoftwareSerial.h"
#include "SerialBridgeFraschetta.h"
class SerialF:SoftwareSerial,public BasicSerialF,public SerialBridgeF{
protected:
 boolean DataPresent()override{return available()>0;}
 void SendLn(String S)override{print(S); print("\n"}
 void SerialBegin(long Baud)override{begin(Baud);}
 uint8_t SerialRead()override{return read();}
 void SerialWrite(uint8_t B)override{write(B);}
public:
 SerialF(uint8_t Rx=2,uint8_t Tx=3,long Baud=9600):SoftwareSerial(Rx,Tx),BasicSerialF(Baud),SerialBridgeF(Baud){}
 template <typename T>
 void Send(T t){print(t);}
 template <typename T>
 void SendLn(T t){print(t); print("\n");}
};
#endif
