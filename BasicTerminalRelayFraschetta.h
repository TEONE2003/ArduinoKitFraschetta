#ifndef BasicTerminalRelayFraschetta_h
#define BasicTerminalRelayFraschetta_h
#include "TerminalDriverObjectFraschetta.h"
#include "RelayFraschetta.h"
class BasicTerminalRelayF:public TerminalDriverObjectF,public RelayF{
protected:
 String TurnOnString,TurnOffString,InvertString,StatusString; virtual void Send(String s)=0;
 BasicTerminalRelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):RelayF(Pin,Type,Save),TerminalDriverObjectF(ReceivedString,Readable){
  TurnOnString=Tag+"=1"; TurnOffString=Tag+"=0";
  StatusString=Tag+".S"; InvertString=Tag+".I";
 }
public:
 void SendStatus(){if(StatusRelay()){Send(TurnOnString);}else{Send(TurnOffString);}}
 void TerminalRelayFunction(){
  if(CommandFound(InvertString)){InvertStatus(); SendStatus();}
  else if(CommandFound(TurnOnString)){TurnOn(); SendStatus();}
  else if(CommandFound(TurnOffString)){TurnOff(); SendStatus();}
  else if(CommandFound(StatusString)||CommandFound(SyncCommand)){SendStatus();}
  else{SetInvalidCommand();}
 }
};
#endif
