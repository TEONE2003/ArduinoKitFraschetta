#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public ThermostatF{
 protected: String StringSetTemperatureThreshold,StringStatusRelay,StringCurrentUmidityRequest,StringCurrentTemperatureRequest,StringTemperatureThresholdRequest;
  int TempIdex,TagLength; bool invalidCommand;
  virtual void Send(String s)=0;
  using ThermostatF::ThermostatFunction;
public:
 BasicSerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):ThermostatF(PinRele,ReleType,TypeT){
  StringTemperatureThresholdRequest=Tag+".TT";
  StringCurrentTemperatureRequest=Tag+".CT";
  StringCurrentUmidityRequest=Tag=".CH";
  StringStatusRelay=".S";
  StringSetTemperatureThreshold=Tag+".T=";
  TempIdex=-1;
  TagLength=Tag.length();
  invalidCommand=0;
 }
 bool InvalidCommand(){return invalidCommand;}
 void SerialThermostatFunction(byte CurrentTemperature,byte CurrentUmidity,String ReceivedString){
  ThermostatFunction(CurrentTemperature);
  invalidCommand=0;
   TempIdex = ReceivedString.indexOf(StringSetTemperatureThreshold);
   if(ReceivedString==StringTemperatureThresholdRequest){Send(String(TemperatureThresholdS));}
   else if(ReceivedString==StringCurrentTemperatureRequest){Send(String(CurrentTemperature));}
   else if(ReceivedString==StringCurrentUmidityRequest){Send(String(CurrentUmidity));}
   else if(ReceivedString==StringStatusRelay){
    if(ReadDigitalStatus()){Send("1");}
    else{Send("0");}
   }
   else if(TempIdex>=0){
    TempIdex=TempIdex+TagLength;
    SetTemperatureThreshold(byte(ReceivedString.substring(TempIdex+4,TempIdex+6).toInt()));
    Send(String(TemperatureThresholdS));
   }
   else if(ReceivedString!=""){invalidCommand=1;}
 }
};
#endif
