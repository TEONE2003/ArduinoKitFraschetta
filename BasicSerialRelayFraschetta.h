#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "RelayFraschetta.h"
class BasicSerialRelayF:public RelayF{
protected: String TurnOnString,TurnOffString,StatusRequestString; bool invalidCommand; virtual void Send(String s)=0;
public:
 BasicSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):RelayF(Pin,Type,Save){
  TurnOnString=Tag+"=1"; TurnOffString=Tag+"=0";
  StatusRequestString=Tag+".S";
  invalidCommand=0;
 }
 bool InvalidCommand(){return invalidCommand;}
 void SendStatus(){
  if(ReadDigitalStatus()){Send("1");}
  else{Send("0");}
 }
 void FunctionSerialRelay(String ReceivedString){
  invalidCommand=0;
  if(ReceivedString==TurnOnString){TurnOn(); Send("1");}
  else if(ReceivedString==TurnOffString){TurnOff(); Send("0");}
  else if(ReceivedString==StatusRequestString){SendStatus();}
  else if(ReceivedString!=""){invalidCommand=1;}
 }
};
#endif
