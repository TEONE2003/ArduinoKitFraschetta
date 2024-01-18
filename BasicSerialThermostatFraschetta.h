#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "TerminalDriverObjectFraschetta.h"
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public TerminalDriverObjectF,public ThermostatF{
 protected: String StringSetTemperatureThreshold,StringStatusRelay,StringStatus,StringTemperatureThresholdRequest,StringTurnOn,StringTurnOff,StringInvertStatus; int TagLength;
  virtual void Send(String s)=0;
  using ThermostatF::ThermostatFunction;
  BasicSerialThermostatF(String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String *ReceivedString):ThermostatF(PinRele,ReleType,TypeT),TerminalDriverObjectF(ReceivedString){
   StringTemperatureThresholdRequest=Tag+".TT";
   StringStatus=Tag+".S";
   StringStatusRelay=Tag+".RS";
   StringSetTemperatureThreshold=StringTemperatureThresholdRequest+"=";
   StringTurnOn=Tag+"=1";
   StringTurnOff=Tag+"=0";
   StringInvertStatus=Tag+".I";
   TagLength=Tag.length();
  }
public:
 void SendStatusRelay(){if(StatusRelay()){Send(StringStatusRelay+"=1");} else{Send(StringStatusRelay+"=0");}}
 void SendStatus(){if(State){Send(StringTurnOn);} else{Send(StringTurnOff);}}
 void SendTemperatureThreshold(){Send(StringSetTemperatureThreshold+String(TemperatureThresholdS));}
 void SerialThermostatFunction(uint8_t CurrentTemperature,String ReceivedString){
  ThermostatFunction(CurrentTemperature);
   
   if(CommandFound(StringTemperatureThresholdRequest)){SendTemperatureThreshold();}
   else if(CommandFound(StringStatusRelay)){SendStatusRelay();}
   else if(CommandFound(StringStatus)){SendStatus();}
   else if(CommandFound(StringTurnOn)){TurnOn(); SendStatus();}
   else if(CommandFound(StringTurnOff)){TurnOff(); SendStatus();}
   else if(CommandFound(StringInvertStatus)){InvertStatus(); SendStatus();}
   else if(ContentCommand(StringSetTemperatureThreshold)){
    SetTemperatureThreshold(uint8_t(ExtractNumber(TagLength+3,2)));
    SendTemperatureThreshold();
   }
   else if(CommandFound(SyncCommand)){SendStatusRelay(); SendStatus(); SendTemperatureThreshold();}
   else{SetInvalidCommand();}
   if(RelayChanged()){SendStatusRelay();}
 }
};
#endif
