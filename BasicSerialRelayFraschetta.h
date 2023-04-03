#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "RelayFraschetta.h"
class BasicSerialRelayF:public SerialDriverObjectF,public RelayF{
protected: String TurnOnString,TurnOffString,StatusRequestString; virtual void Send(String s)=0;
public:
 BasicSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):RelayF(Pin,Type,Save),SerialDriverObjectF(){
  TurnOnString=Tag+"=1"; TurnOffString=Tag+"=0";
  StatusRequestString=Tag+".S";
 }
 void SendStatus(){
  if(ReadDigitalStatus()){Send("1");}
  else{Send("0");}
 }
 void FunctionSerialRelay(String ReceivedString){
  SetReceivedString(ReceivedString);
  if(CommandFound(TurnOnString)){TurnOn(); Send("1");}
  else if(CommandFound(TurnOffString)){TurnOff(); Send("0");}
  else if(CommandFound(StatusRequestString)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
