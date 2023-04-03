#ifndef BasicSerialServoEntranceFraschetta_h
#define BasicSerialServoEntranceFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "ServoEntranceFraschetta.h"
class BasicSerialServoEntranceF:public SerialDriverObjectF,public ServoEntranceF{
protected: String OpenString,CloseString,StatusRequestString; virtual void Send(String s)=0;
 BasicSerialServoEntranceF(String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition, uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
     ServoEntranceF(Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),SerialDriverObjectF(){
      OpenString=Tag+".O"; CloseString=Tag+".C";
      StatusRequestString=Tag+".S";
    }
public:
 void SendStatus(){
  if(Opened()){Send("O");}
  else if(Closed()){Send("C");}
 }
void FunctionSerialServoEntrance(String ReceivedString){
  SetReceivedString(ReceivedString);
  if(CommandFound(OpenString)){Open(); Send("O");}
  else if(CommandFound(CloseString)){Close(); Send("C");}
  else if(CommandFound(StatusRequestString)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
