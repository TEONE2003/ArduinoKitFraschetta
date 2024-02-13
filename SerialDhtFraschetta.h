#ifndef SerialDhtFraschetta_h
#define SerialDhtFraschetta_h
#include "BasicTerminalDhtFraschetta.h"
#include "SerialFraschetta.h"
class SerialDhtF:SerialF,public BasicSerialDhtF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public: SerialDhtF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint8_t Type,uint8_t Rx=2,uint8_t Tx=3):BasicSerialDhtF(ReceivedString,Readable,Tag,Pin,Type),SerialF(Rx,Tx){}
void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicSerialDhtF::Begin();}
}
#endif
