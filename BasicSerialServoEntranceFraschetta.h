#ifndef BasicSerialServoEntranceFraschetta_h
#define BasicSerialServoEntranceFraschetta_h
#include "ServoEntranceFraschetta.h"
class BasicSerialServoEntranceF:public ServoEntranceF{
protected: String OpenString,CloseString,StatusRequestString; bool invalidCommand; virtual void Send(String s)=0;
public:
 BasicSerialServoEntranceF(String Tag,String StatusRequestString,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
  uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
  ServoEntranceF(Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds){
   OpenString=Tag+'1'; CloseString=Tag+'0';
   this->StatusRequestString=StatusRequestString;
   invalidCommand=0;
 }
 bool InvalidCommand(){return invalidCommand;}
 void SendState(){
  if(Opened()){Send(OpenString);}
  else if(Closed()){Send(CloseString);}
 }
void FunctionSerialServoEntrance(String ReceivedString){
  invalidCommand=0;
  if(ReceivedString==OpenString){Open(); Send(OpenString);}
  else if(ReceivedString==CloseString){Close(); Send(CloseString);}
  else if(ReceivedString==StatusRequestString){SendState();}
  else{invalidCommand=1;}
 }
};
#endif
