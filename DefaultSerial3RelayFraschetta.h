#ifndef DefaultSerial3RelayFraschetta_h
#define DefaultSerial3RelayFraschetta_h
#include "BasicSerialRelay.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3RelayF:DefaultSerial3F,public BasicSerialRelay{
public:
 DefaultSerial3RelayF(){}
 DefaultSerial3RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):DefaultSerial3F(Baud){}
 void Send(String s)override{DefaultSerial3F:Send(s);}
};
#endif
