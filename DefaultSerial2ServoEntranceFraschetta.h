#ifndef DefaultSerial2ServoEntranceFraschettaa_h
#define DefaultSerial2ServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ServoEntranceF:DefaultSerial2F,public BasicSerialServoEntranceF{
protected: void Send(String s)override{DefaultSerial2F::SendLn(s);}
public:
    DefaultSerial2ServoEntranceF(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceF(Tag,StatusRequestString,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
    DefaultSerial2F(Baud){}
};
#endif