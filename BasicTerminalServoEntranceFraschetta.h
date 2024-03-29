#ifndef BasicTerminalServoEntranceFraschetta_h
#define BasicTerminalServoEntranceFraschetta_h
#include "TerminalDriverObjectFraschetta.h"
#include "ServoEntranceFraschetta.h"
class BasicTerminalServoEntranceF:public TerminalDriverObjectF,public ServoEntranceF{
protected: String OpenString,CloseString,InvertString,StatusRequestString; virtual void Send(String s)=0;
 BasicTerminalServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition, uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):
     ServoEntranceF(Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds),TerminalDriverObjectF(ReceivedString,Readable){
      OpenString=Tag+"=O"; CloseString=Tag+"=C";
      StatusRequestString=Tag+".S"; InvertString=Tag+".I";
    }
public:
 void SendStatus(){if(Opened()){Send(OpenString);} else{Send(CloseString);}}
 void TerminalServoEntranceFunction(){
  if(CommandFound(InvertString)){Invert(); SendStatus();}
  else if(CommandFound(OpenString)){Open(); SendStatus();}
  else if(CommandFound(CloseString)){Close(); SendStatus();}
  else if(CommandFound(StatusRequestString)||CommandFound(SyncCommand)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
