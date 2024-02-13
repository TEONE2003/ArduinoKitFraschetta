#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial3ServoEntranceFraschetta_h
#define DefaultSerial3ServoEntranceFraschetta_h
#include "BasicTerminalServoEntranceFraschetta.h"
#include "DefaultSerial3Fraschetta.h"
class DefaultSerial3ServoEntranceF:DefaultSerial3F,public BasicTerminalServoEntranceF{
protected: void Send(String s)override{DefaultSerial3F:SendLn(s);}
public:
    DefaultSerial3ServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
     BasicTerminalServoEntranceF(ReceivedString,Readable,Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
     DefaultSerial3F(){}
    void Begin(long Baud=9600){DefaultSerial3F::SetBaudRate(Baud); BasicTerminalServoEntranceF::Begin();}
};
#endif
#endif
