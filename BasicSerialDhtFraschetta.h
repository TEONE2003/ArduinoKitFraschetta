#ifndef BasicSerialDhtFraschetta_h
#define BasicSerialDhtFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "DhtFraschetta.h"
class BasicSerialDhtF:public SerialDriverObjectF,public DhtF{
protected:
  String StringCurrentHumidityRequest,StringCurrentTemperatureRequest;
  virtual void Send(String s)=0;
  BasicSerialDhtF(String Tag,uint8_t Pin,uint8_t Type):DhtF(Pin,Type),SerialDriverObjectF(){
   StringCurrentTemperatureRequest=Tag+".T";
   StringCurrentHumidityRequest=Tag+".H";
  }
 public:
  void SendTemperature(){Send(StringCurrentTemperatureRequest+"="+String(ReadTemperature()));}
  void SendHumidity(){Send(StringCurrentHumidityRequest+"="+String(ReadHumidity()));}
  void SerialDhtFFunction(String ReceivedString){
   SetReceivedString(ReceivedString);
   if(CommandFound(StringCurrentTemperatureRequest)){SendTemperature();}
   else if(CommandFound(StringCurrentHumidityRequest)){SendHumidity();}
   else{SetInvalidCommand();}
   if(TemperatureChanged()){SendTemperature();}
   if(HumidityChanged()){SendHumidity();}
  }
};
#endif
