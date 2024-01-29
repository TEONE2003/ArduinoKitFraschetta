#ifndef BasicTerminalDhtFraschetta_h
#define BasicTerminalDhtFraschetta_h
#include "TerminalDriverObjectFraschetta.h"
#include "DhtFraschetta.h"
class BasicSerialDhtF:public TerminalDriverObjectF,public DhtF{
protected:
  String StringCurrentHumidityRequest,StringCurrentTemperatureRequest;
  virtual void Send(String s)=0;
  BasicSerialDhtF(String Tag,uint8_t Pin,uint8_t Type,String *ReceivedString,bool *Readable):DhtF(Pin,Type),TerminalDriverObjectF(ReceivedString,Readable){
   StringCurrentTemperatureRequest=Tag+".T";
   StringCurrentHumidityRequest=Tag+".H";
  }
 public:
  void SendTemperature(){Send(StringCurrentTemperatureRequest+"="+String(ReadTemperature()));}
  void SendHumidity(){Send(StringCurrentHumidityRequest+"="+String(ReadHumidity()));}
  void SerialDhtFFunction(){
   if(CommandFound(StringCurrentTemperatureRequest)){SendTemperature();}
   else if(CommandFound(StringCurrentHumidityRequest)){SendHumidity();}
   else if(CommandFound(SyncCommand)){SendTemperature(); SendHumidity();}
   else{SetInvalidCommand();}
   if(TemperatureChanged()){SendTemperature();}
   if(HumidityChanged()){SendHumidity();}
  }
};
#endif
