#ifndef BasicSerialServoEntranceFraschetta_h
#define BasicSerialServoEntranceFraschetta_h
#include "ServoEntranceFraschetta.h"
class BasicSerialServoEntranceF:public ServoEntranceF{
protected: String OpenString,CloseString,StatusRequestString; bool invalidCommand; virtual void Send(String s)=0;
public:
 BasicSerialServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition,
  uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
  ServoEntranceF(Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds){
   OpenString=Tag+"=1"; CloseString=Tag+"=0";
   StatusRequestString=Tag+".S";
   invalidCommand=0;
 }
 bool InvalidCommand(){return invalidCommand;}
 void SendStatus(){
  if(Opened()){Send("1");}
  else if(Closed()){Send("0");}
 }
void FunctionSerialServoEntrance(String ReceivedString){
  invalidCommand=0;
  if(ReceivedString==OpenString){Open(); Send(OpenString);}
  else if(ReceivedString==CloseString){Close(); Send(CloseString);}
  else if(ReceivedString==StatusRequestString){SendStatus();}
  else if(ReceivedString!=""){invalidCommand=1;}
 }
};
#endif
