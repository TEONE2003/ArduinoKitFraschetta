#ifndef DefaultSerial1ServoEntranceFraschetta_h
#define DefaultSerial1ServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
class DefaultSerial1ServoEntranceFraschetta:DefaultSerial1F,public BasicSerialServoEntranceFraschetta{
protected: void Send(String s)override{DefaultSerial1F::SendLn(s);}
public:
    DefaultSerial1ServoEntranceFraschetta(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceFraschetta(Tag,StatusRequestString,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds):
    DefaultSerial1F(Baud){}
};
#endif
