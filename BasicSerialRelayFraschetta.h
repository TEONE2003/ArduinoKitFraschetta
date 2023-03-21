#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "RelayFraschetta.h"
class BasicSerialRelay:public RelayF{
protected: String TurnOnString,TurnOffString,StatusRequestString;
public:
 BasicSerialRelay(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String StatusRequestString=""):RelayF(Pin,Type,Save){
  TurnOnString=Tag+'1'; TurnOffString=Tag+'0';
  this->StatusRequestString=StatusRequestString;
 }
 virtual void Send(String s)=0
 void SendState(){
  if(ReadDigitalStatus()){Send(TurnOnString);}
  else{Send(TurnOffString);}
 }
 void FuncionSerialRelay(String ReceivedString){
  if(ReceivedString == TurnOnString){TurnOn(); Send(TurnOnString);}
  else if(ReceivedString == TurnOffString){TurnOff(); Send(TurnOffString);}
  if(ReceivedString!="" && ReceivedString==StatusRequestString){SendState();}
 }
};
#endif
