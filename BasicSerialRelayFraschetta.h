#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "RelayFraschetta.h"
class BasicSerialRelayF:public SerialDriverObjectF,public RelayF{
protected:
 String TurnOnString,TurnOffString,InvertString,StatusString; virtual void Send(String s)=0;
 BasicSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):RelayF(Pin,Type,Save),SerialDriverObjectF(){
  TurnOnString=Tag+"=1"; TurnOffString=Tag+"=0";
  StatusString=Tag+".S"; InvertString=Tag+".I";
 }
public:
 void SendStatus(){if(ReadDigitalStatus()){Send(TurnOnString);}else{Send(TurnOffString);}}
 void FunctionSerialRelay(String ReceivedString){
  SetReceivedString(ReceivedString);
  if(CommandFound(InvertString)){InvertStatus(); SendStatus();}
  else if(CommandFound(TurnOnString)){TurnOn(); SendStatus();}
  else if(CommandFound(TurnOffString)){TurnOff(); SendStatus();}
  else if(CommandFound(StatusString)||CommandFound(SyncCommand)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
