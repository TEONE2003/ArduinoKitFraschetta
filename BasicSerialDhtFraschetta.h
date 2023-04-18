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
  void SerialDhtFFunction(String ReceivedString){
   SetReceivedString(ReceivedString);
   if(CommandFound(StringCurrentTemperatureRequest)){Send(StringCurrentTemperatureRequest+"="+String(ReadTemperature()));}
   else if(CommandFound(StringCurrentHumidityRequest)){Send(StringCurrentHumidityRequest+"="+String(ReadHumidity()));}
   else{SetInvalidCommand();}
   if(TemperatureChanged()){Send(StringCurrentTemperatureRequest+"="+String(ReadTemperature()));}
   if(HumidityChanged()){Send(StringCurrentHumidityRequest+"="+String(ReadHumidity()));}
  }
};
#endif
