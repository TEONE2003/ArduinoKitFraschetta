#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "SerialFraschetta.h"
class SerialRelayF:SerialF,public BasicSerialRelayF{
protected: void Send(String s)override{SerialF:SendLn(s);}
public:
 SerialRelayF(){}
 SerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint8_t RX=2,uint8_t TX=3,uint32_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save,StatusRequestString),SerialF(RX,TX,Baud){}
};
#endif
