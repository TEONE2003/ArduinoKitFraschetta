#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include "BasicSerialFraschetta.h"
#include "SoftwareSerial.h"
class SerialF:SoftwareSerial,public BasicSerialF{
protected:
 bool SerialBridge;
 boolean DataPresent()override{return available()>0;}
 void SerialEnd()override{return end();}
 void SerialBegin(long Baud)override{return begin(Baud);}
 uint8_t SerialRead()override{return read();}
public:
 SerialF(uint8_t Rx=2,uint8_t Tx=3,long Baud=9600):SoftwareSerial(Rx,Tx),BasicSerialF(Baud){SerialBridge=0;}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); print(t); print("\n");}
 void SerialBridgeFunction(){
  InitializeIfNotInitialized();
  if(!SerialBridge){Serial.end(); Serial.begin(Baud); SerialBridge=1;}
  if(Serial.available()){write(Serial.read());}
  if(available()){Serial.write(read());}
}
};
#endif
