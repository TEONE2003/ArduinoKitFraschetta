#ifndef BasicSerialRelayFraschetta_h
#define BasicSerialRelayFraschetta_h
#include "TerminalDriverObjectFraschetta.h"
#include "RelayFraschetta.h"
class BasicSerialRelayF:public TerminalDriverObjectF,public RelayF{
protected:
 String TurnOnString,TurnOffString,InvertString,StatusString; virtual void Send(String s)=0;
 BasicSerialRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,String *ReceivedString):RelayF(Pin,Type,Save),TerminalDriverObjectF(ReceivedString){
  TurnOnString=Tag+"=1"; TurnOffString=Tag+"=0";
  StatusString=Tag+".S"; InvertString=Tag+".I";
 }
public:
 void SendStatus(){if(StatusRelay()){Send(TurnOnString);}else{Send(TurnOffString);}}
 void FunctionSerialRelay(){
  if(CommandFound(InvertString)){InvertStatus(); SendStatus();}
  else if(CommandFound(TurnOnString)){TurnOn(); SendStatus();}
  else if(CommandFound(TurnOffString)){TurnOff(); SendStatus();}
  else if(CommandFound(StatusString)||CommandFound(SyncCommand)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
