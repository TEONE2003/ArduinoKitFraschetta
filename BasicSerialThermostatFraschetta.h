#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public SerialDriverObjectF,public ThermostatF{
 protected: String StringSetTemperatureThreshold,StringStatusRelay,StringTemperatureThresholdRequest;
  int TempIdex,TagLength; bool invalidCommand;
  virtual void Send(String s)=0;
  using ThermostatF::ThermostatFunction;
  BasicSerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):ThermostatF(PinRele,ReleType,TypeT),SerialDriverObjectF(){
   StringTemperatureThresholdRequest=Tag+".TT";
   StringStatusRelay=Tag+".S";
   StringSetTemperatureThreshold=Tag+"=";
   TempIdex=-1;
   TagLength=Tag.length();
  }
public:
 void SerialThermostatFunction(byte CurrentTemperature,String ReceivedString){
  ThermostatFunction(CurrentTemperature);
   SetReceivedString(ReceivedString);
   TempIdex = ReceivedString.indexOf(StringSetTemperatureThreshold);
   if(CommandFound(StringTemperatureThresholdRequest)){Send(String(TemperatureThresholdS));}
   else if(CommandFound(StringStatusRelay)){
    if(ReadDigitalStatus()){Send("1");}
    else{Send("0");}
   }
   else if(TempIdex>=0){
    TempIdex=TempIdex+TagLength;
    SetTemperatureThreshold(byte(ReceivedString.substring(TempIdex+1,TempIdex+3).toInt()));
    Send(String(TemperatureThresholdS));
   }
   else{SetInvalidCommand();}
 }
};
#endif
