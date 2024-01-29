#ifndef SerialPhotocellDuskToDawnFraschetta_h
#define SerialPhotocellDuskToDawnFraschetta_h
#include "BasicTerminalPhotocellDuskToDawnFraschetta.h"
#include "SerialFraschetta.h"
class SerialPhotocellDuskToDawnF:public BasicTerminalPhotocellDuskToDawnF,SerialF{
protected: void Send(String s)override{SerialF::SendLn(s);}
public:
 SerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,uint8_t PinRele,DigitalType ReleType,uint8_t Rx=2,uint8_t Tx=3,String *ReceivedString,bool *Readable):BasicTerminalPhotocellDuskToDawnF(Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType,ReceivedString,Readable),SerialF(Rx,Tx){}
 void Begin(long Baud=9600){SerialF::SetBaudRate(Baud); BasicTerminalPhotocellDuskToDawnF::Begin();}
};
#endif
