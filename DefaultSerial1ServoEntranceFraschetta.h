#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1ServoEntranceFraschetta_h
#define DefaultSerial1ServoEntranceFraschetta_h
#include "BasicSerialServoEntranceFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1ServoEntranceF:DefaultSerial1F,public BasicSerialServoEntranceF{
protected: void Send(String s)override{DefaultSerial1F:SendLn(s);}
public:
    DefaultSerial1ServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,uint32_t Baud=9600):
     BasicSerialServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
    DefaultSerial1F(Baud){}
    void Begin(){DefaultSerial1F::Begin(); BasicSerialServoEntranceF::Begin();}
};
#endif
#endif
