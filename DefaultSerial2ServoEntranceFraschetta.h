#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
#ifndef DefaultSerial2ServoEntranceFraschetta_h
#define DefaultSerial2ServoEntranceFraschetta_h
#include "BasicTerminalServoEntranceFraschetta.h"
#include "DefaultSerial2Fraschetta.h"
class DefaultSerial2ServoEntranceF:DefaultSerial2F,public BasicTerminalServoEntranceF{
protected: void Send(String s)override{DefaultSerial2F:SendLn(s);}
public:
    DefaultSerial2ServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
     BasicTerminalServoEntranceF(ReceivedString,Readable,Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),
    DefaultSerial2F(){}
    void Begin(long Baud=9600){DefaultSerial2F::SetBaudRate(Baud); BasicTerminalServoEntranceF::Begin();}
};
#endif
#else
#error This library requires Arduino Mega.
#endif
