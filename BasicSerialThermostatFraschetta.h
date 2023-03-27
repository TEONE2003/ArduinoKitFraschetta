#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public ThermostatF{
 protected: String Tag,StatusRequestString; int TempIdex; bool invalidCommand;
  virtual void Send(String s)=0;
   String Status(){
       if(ReadDigitalStatus()){return "1";}
       else{return "0";}
    }
    using ThermostatF::ThermostatFunction;
public:
    BasicSerialThermostatF(uint8_t PinRele,String Tag,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString=""):ThermostatF(PinRele,ReleType,TypeT){
        this->StatusRequestString=StatusRequestString;
        this->Tag=Tag;
        TempIdex=-1;
        invalidCommand=0;
    }
    
    void SendState(byte CurrentTemperature,byte CurrentUmidity){Send(Tag+" T="+String(TemperatureThresholdS)+" T:"+String(CurrentTemperature)+" U:"+String(CurrentUmidity)+" S:"+Status());}
    
    bool InvalidCommand(){return invalidCommand;}
    
    void SerialThermostatFunction(byte CurrentTemperature,byte CurrentUmidity,String ReceivedString){
        ThermostatFunction(CurrentTemperature);
        invalidCommand=0;
        if(nTick()){
            TempIdex = ReceivedString.indexOf(Tag+" T=");
            if(ReceivedString==StatusRequestString){SendState(CurrentTemperature,CurrentUmidity);}
            else if(TempIdex>=0){
                TempIdex=TempIdex+Tag.length();
                SetTemperatureThreshold(byte(ReceivedString.substring(TempIdex+4,TempIdex+6).toInt()));
            }
            else if(ReceivedString!=""){invalidCommand=1;}
        }
    }
};
#endif
