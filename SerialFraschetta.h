#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include <BasicSerialFraschetta.h>
#include <SoftwareSerial.h>
class SerialF:SoftwareSerial,public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){end(); begin(Baud); I=1;}}
 boolean DataPresent()override{return available()>0;}
 String String()override{return readString();}
 uint8_t Byte()override{return read();}
 char Char()override{return read();}
public:
 SerialF(uint8_t RX=2,uint8_t TX=3,uint32_t Baud=9600):SoftwareSerial(RX,TX),BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); print(t);}
 template <typename T>
 void SendLN(T t){InitializeIfNotInitialized(); println(t);}
 void SerialBridge(){
  InitializeIfNotInitialized();
  if(!SerialBridge){Serial.end(); Serial.begin(9600); SerialBridge=1;}
  if(Serial.available()){write(Serial.read());}
  if(available()){Serial.write(read());}
}
};
#endif
