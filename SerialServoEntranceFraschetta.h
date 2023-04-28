#ifndef SerialServoEntranceFraschetta_h
#define SerialServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "SerialFraschetta.h"
class SerialServoEntranceF:SerialF,public BasicSerialServoEntranceF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
    SerialServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint8_t Rx=2,uint8_t Tx=3,uint32_t Baud=9600):
     BasicSerialServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
     SerialF(Rx,Tx,Baud){}
    void Begin(){SerialF::Begin(); BasicSerialServoEntranceF::Begin();}
};
#endif
