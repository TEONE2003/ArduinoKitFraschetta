#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include "BasicSerialFraschetta.h"
#include "SoftwareSerial.h"
class SerialF:SoftwareSerial,public BasicSerialF{
protected:
 bool SerialBridge;
 void InitializeIfNotInitialized()override{if(!Initialized()){end(); begin(Baud); I=1;}}
 boolean DataPresent()override{return available()>0;}
 uint8_t SerialRead()override{return read();}
 void SerialEnd()override{return end();}
 void SerialBegin()override{return begin();}
public:
 SerialF(uint8_t Rx=2,uint8_t Tx=3,uint32_t Baud=9600):SoftwareSerial(Rx,Tx),BasicSerialF(Baud){SerialBridge=0;}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); println(t);}
 void SerialBridgeFunction(){
  InitializeIfNotInitialized();
  if(!SerialBridge){Serial.end(); Serial.begin(9600); SerialBridge=1;}
  if(Serial.available()){write(Serial.read());}
  if(available()){Serial.write(read());}
}
};
#endif
