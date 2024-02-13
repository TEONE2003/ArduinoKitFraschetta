#ifndef DefaultSerialServoEntranceFraschetta_h
#define DefaultSerialServoEntranceFraschetta_h
#include "BasicTerminalServoEntranceFraschetta.h"
#include "DefaultSerialFraschetta.h"
class DefaultSerialServoEntranceF:DefaultSerialF,public BasicTerminalServoEntranceF{
protected: void Send(String s)override{DefaultSerialF:SendLn(s);}
public:
    DefaultSerialServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
     BasicTerminalServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds,ReceivedString,Readable),
    DefaultSerialF(){}
    void Begin(long Baud=9600){DefaultSerialF::SetBaudRate(Baud); BasicTerminalServoEntranceF::Begin();}
};
#endif
