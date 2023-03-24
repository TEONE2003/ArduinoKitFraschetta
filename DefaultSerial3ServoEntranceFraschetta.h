#ifndef DefaultSerial3ServoEntranceFraschetta_h
#define DefaultSerial3ServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3ServoEntranceF:DefaultSerial3F,public BasicSerialServoEntranceF{
protected: void Send(String s)override{DefaultSerial3F::SendLn(s);}
public:
    DefaultSerial3ServoEntranceF(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceF(Tag,StatusRequestString,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
    DefaultSerial3F(Baud){}
};
#endif
