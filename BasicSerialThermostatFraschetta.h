#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "SerialDriverObjectFraschetta.h"
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public SerialDriverObjectF,public ThermostatF{
 protected: String StringSetTemperatureThreshold,StringStatusRelay,StringStatus,StringTemperatureThresholdRequest,StringTurnOn,StringTurnOff;
  int TempIdex,TagLength;
  virtual void Send(String s)=0;
  using ThermostatF::ThermostatFunction;
  BasicSerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):ThermostatF(PinRele,ReleType,TypeT),SerialDriverObjectF(){
   StringTemperatureThresholdRequest=Tag+".TT";
   StringStatus=Tag+".S";
   StringStatusRelay=Tag+".RS";
   StringSetTemperatureThreshold=Tag+"=";
   StringTurnOn=Tag+".ON";
   StringTurnOff=Tag+".OFF";
   TempIdex=-1;
   TagLength=Tag.length();
  }
public:
 void SendStatusRelay(){if(ReadDigitalStatus()){Send("1");} else{Send("0");}}
 void SendStatus(){if(State){Send("1");} else{Send("0");}}
 void SerialThermostatFunction(byte CurrentTemperature,String ReceivedString){
  ThermostatFunction(CurrentTemperature);
   SetReceivedString(ReceivedString);
   TempIdex = ReceivedString.indexOf(StringSetTemperatureThreshold);
   if(CommandFound(StringTemperatureThresholdRequest)){Send(String(TemperatureThresholdS));}
   else if(CommandFound(StringStatusRelay)){SendStatusRelay();}
   else if(CommandFound(StringStatus)){SendStatus();}
   else if(CommandFound(StringTurnOn)){TurnOn(); SendStatus();}
   else if(CommandFound(StringTurnOff)){TurnOff(); SendStatus();}
   else if(TempIdex>=0){
    TempIdex=TempIdex+TagLength;
    SetTemperatureThreshold(byte(ReceivedString.substring(TempIdex+1,TempIdex+3).toInt()));
    Send(String(TemperatureThresholdS));
   }
   else{SetInvalidCommand();}
 }
};
#endif
