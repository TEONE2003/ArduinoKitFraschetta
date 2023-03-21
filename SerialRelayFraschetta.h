#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "BasicSerialRelay.h"
#include "SerialFraschetta.h"
class SerialRelayF:SerialF,public BasicSerialRelay{
public:
 SerialRelayF(){}
 SerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint8_t RX=2,uint8_t TX=3,uint32_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):SerialF(RX,TX,Baud){}
 void Send(String s)override{SerialF:Send(s);}
};
#endif
