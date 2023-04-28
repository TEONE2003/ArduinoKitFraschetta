#ifndef SerialBridgeFraschetta_h
#define SerialBridgeFraschetta_h
class SerialBridgeF{
private:
 bool SerialBridge; long Baud;
 virtual uint8_t SerialRead()=0;
 virtual void SerialWrite(uint8_t B)=0;
 virtual bool DataPresent()=0;
protected: SerialBridgeF(long Baud=9600){this->Baud=Baud; SerialBridge=0;}
public:
void SerialBridgeFunction(){
  if(!SerialBridge){Serial.end(); Serial.begin(Baud); SerialBridge=1;}
  if(Serial.available()>0){SerialWrite(Serial.read());}
  if(DataPresent()){Serial.write(SerialRead());}
}
};
#endif