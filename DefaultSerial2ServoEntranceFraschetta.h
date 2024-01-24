#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial2ServoEntranceFraschetta_h
#define DefaultSerial2ServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ServoEntranceF:DefaultSerial2F,public BasicSerialServoEntranceF{
protected: void Send(String s)override{DefaultSerial2F:SendLn(s);}
public:
    DefaultSerial2ServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,String *ReceivedString):
     BasicSerialServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds,ReceivedString),
    DefaultSerial2F(){}
    void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicSerialServoEntranceF::Begin();}
};
#endif
#endif
