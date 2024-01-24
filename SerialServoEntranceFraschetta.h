#ifndef SerialServoEntranceFraschetta_h
#define SerialServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "SerialFraschetta.h"
class SerialServoEntranceF:SerialF,public BasicSerialServoEntranceF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
    SerialServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint8_t Rx=2,uint8_t Tx=3,String *ReceivedString):
     BasicSerialServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds,ReceivedString),
     SerialF(Rx,Tx){}
    void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicSerialServoEntranceF::Begin();}
};
#endif
