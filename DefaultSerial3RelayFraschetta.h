#ifndef DefaultSerial3RelayFraschetta_h
#define DefaultSerial3RelayFraschetta_h
#include "BasicSerialRelay.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3RelayF:DefaultSerial3F,public BasicSerialRelay{
protected: void Send(String s)override{DefaultSerial3F:SendLn(s);}
public:
 DefaultSerial3RelayF(){}
 DefaultSerial3RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString="",uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save,StatusRequestString):DefaultSerial3F(Baud){}
};
#endif
