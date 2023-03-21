#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "BasicSerialRelay.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1RelayF:DefaultSerial1F,public BasicSerialRelay{
public:
 DefaultSerial1RelayF(){}
 DefaultSerial1RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save,StatusRequestString):DefaultSerial1F(Baud){}
 void Send(String s)override{DefaultSerial1F:Send(s);}
};
#endif
