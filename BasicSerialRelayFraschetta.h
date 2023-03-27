#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "RelayFraschetta.h"
class BasicSerialRelayF:public RelayF{
protected: String TurnOnString,TurnOffString,StatusRequestString; bool invalidCommand; virtual void Send(String s)=0;
public:
 BasicSerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString=""):RelayF(Pin,Type,Save){
  TurnOnString=Tag+'1'; TurnOffString=Tag+'0';
  this->StatusRequestString=StatusRequestString;
 }
 bool InvalidCommand(){return invalidCommand;}
 void SendState(){
  if(ReadDigitalStatus()){Send(TurnOnString);}
  else{Send(TurnOffString);}
 }
 void FunctionSerialRelay(String ReceivedString){
  invalidCommand=0;
  if(ReceivedString == TurnOnString){TurnOn(); Send(TurnOnString);}
  else if(ReceivedString == TurnOffString){TurnOff(); Send(TurnOffString);}
  if(ReceivedString==StatusRequestString){SendState();}
  else if(ReceivedString!=""){invalidCommand=1;}
 }
};
#endif