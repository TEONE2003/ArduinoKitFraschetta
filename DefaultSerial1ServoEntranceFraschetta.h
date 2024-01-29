#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
#ifndef DefaultSerial1ServoEntranceFraschetta_h
#define DefaultSerial1ServoEntranceFraschetta_h
#include "BasicTerminalServoEntranceFraschetta.h"
#include "DefaultSerial1Fraschetta.h"
class DefaultSerial1ServoEntranceF:DefaultSerial1F,public BasicTerminalServoEntranceF{
protected: void Send(String s)override{DefaultSerial1F:SendLn(s);}
public:
    DefaultSerial1ServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
     uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds,String *ReceivedString):
     BasicTerminalServoEntranceF(Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds,ReceivedString),
    DefaultSerial1F(){}
    void Begin(long Baud=9600){DefaultSerial1F::SetBaudRate(Baud); BasicTerminalServoEntranceF::Begin();}
};
#endif
#endif
