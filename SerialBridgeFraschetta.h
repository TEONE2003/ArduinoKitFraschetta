#ifndef SerialBridgeFraschetta_h
#define SerialBridgeFraschetta_h
#include "SerialBeginFraschetta.h"
class SerialBridgeF{
private:
 virtual uint8_t SerialRead()=0;
 virtual void SerialWrite(uint8_t B)=0;
 virtual bool DataPresent()=0;
protected: SerialBridgeF(){}
public:
void SetBaudRate(long Baud){SerialBeginF(Baud);}
void SerialBridgeFunction(){
  while(Serial.available()>0){SerialWrite(Serial.read());}
  while(DataPresent()){Serial.write(SerialRead());}
}
};
#endif