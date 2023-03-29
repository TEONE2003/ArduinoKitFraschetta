#ifndef BasicSerialDhtFraschetta_h
#define BasicSerialDhtFraschetta_h
#include "DhtFraschetta.h"
class BasicSerialDhtF:public DhtF{
protected: String StringCurrentUmidityRequest,StringCurrentTemperatureRequest; bool invalidCommand;
  virtual void Send(String s)=0;
 public:
  BasicSerialDhtF(String Tag,uint8_t Pin,uint8_t Type):DhtF(Pin,Type){
   StringCurrentTemperatureRequest=Tag+".CT";
   StringCurrentUmidityRequest=Tag=".CH";
  }
    bool InvalidCommand(){return invalidCommand;}
    void SerialDhtFFunction(String ReceivedString){
     invalidCommand=0;
     if(ReceivedString==StringCurrentTemperatureRequest){Send(String(byte(ReadTemperature())));}
     else if(ReceivedString==StringCurrentUmidityRequest){Send(String(byte(ReadHumidity())));}
     else if(ReceivedString!=""){invalidCommand=1;}
    }
};
#endif
