#ifndef SerialBridgeFraschetta_h
#define SerialBridgeFraschetta_h
#include "ExecuteOnceFraschetta.h"
class SerialBridgeF{
private:
 long Baud;
 virtual uint8_t SerialRead()=0;
 virtual void SerialWrite(uint8_t B)=0;
 virtual bool DataPresent()=0;
protected: SerialBridgeF(long Baud=9600){this->Baud=Baud;}
public:
void SerialBridgeFunction(){
  static ExecuteOnceF EB=ExecuteOnceF();
  if(EB.NoExecuted()){Serial.end(); Serial.begin(Baud);}
  while(Serial.available()>0){SerialWrite(Serial.read());}
  while(DataPresent()){Serial.write(SerialRead());}
}
};
#endif