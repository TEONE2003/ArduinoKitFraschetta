#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "BasicSerialRelayFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1RelayF:DefaultSerial1F,public BasicSerialRelayF{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
 DefaultSerial1RelayF(){}
 DefaultSerial1RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelayF(Pin,Tag,Type,Save,StatusRequestString),DefaultSerial1F(Baud){}
};
#endif
