#ifndef DefaultSerialServoEntranceFraschetta_h
#define DefaultSerialServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
class DefaultSerialServoEntranceFraschetta:DefaultSerialF,public BasicSerialServoEntranceFraschetta{
protected: void Send(String s)override{DefaultSerialF:SendLn(s);}
public:
    DefaultSerialServoEntranceFraschetta(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceFraschetta(Tag,StatusRequestString,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds):
    DefaultSerialF(Baud){}
};
#endif
