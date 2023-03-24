#ifndef DefaultSerialServoEntranceFraschetta_h
#define DefaultSerialServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialServoEntranceF:DefaultSerialF,public BasicSerialServoEntranceF{
protected: void Send(String s)override{DefaultSerialF:SendLn(s);}
public:
    DefaultSerialServoEntranceF(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceF(Tag,StatusRequestString,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
    DefaultSerialF(Baud){}
};
#endif
