#ifndef SerialServoEntranceFraschetta_h
#define SerialServoEntranceFraschetta_h
#include "BasicTerminalServoEntranceFraschetta.h"
#include "SerialFraschetta.h"
class SerialServoEntranceF:SerialF,public BasicTerminalServoEntranceF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
    SerialServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint8_t Rx=2,uint8_t Tx=3):
     BasicTerminalServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds,ReceivedString,Readable),
     SerialF(Rx,Tx){}
    void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicTerminalServoEntranceF::Begin();}
};
#endif
