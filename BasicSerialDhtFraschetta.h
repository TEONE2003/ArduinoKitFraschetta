#ifndef BasicSerialDhtFraschetta_h
#define BasicSerialDhtFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "DhtFraschetta.h"
class BasicSerialDhtF:public SerialDriverObjectF,public DhtF{
protected: String StringCurrentUmidityRequest,StringCurrentTemperatureRequest;
  virtual void Send(String s)=0;
 public:
  BasicSerialDhtF(String Tag,uint8_t Pin,uint8_t Type):DhtF(Pin,Type),SerialDriverObjectF(){
   StringCurrentTemperatureRequest=Tag+".CT";
   StringCurrentUmidityRequest=Tag+".CH";
  }
    void SerialDhtFFunction(String ReceivedString){
     SetReceivedString(ReceivedString);
     if(CommandFound(StringCurrentTemperatureRequest)){Send(String(byte(ReadTemperature())));}
     else if(CommandFound(StringCurrentUmidityRequest)){Send(String(byte(ReadHumidity())));}
     else{SetInvalidCommand();}
    }
};
#endif
