#ifndef BasicSerialThermostatFraschetta_h
#define BasicSerialThermostatFraschetta_h
#include "ThermostatFraschetta.h"
class BasicSerialThermostatF:public ThermostatF{
 protected: String Tag,StatusRequestString; int TempIdex; bool invalidCommand;
  using ThermostatF::ThermostatFunction;
  virtual void Send(String s)=0;
   String Status(){
       if(ReadDigitalStatus()){return "ON"}
       else{return "OFF"}
    }
public:
    BasicSerialThermostatF(uint8_t PinRele,String Tag,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating,String StatusRequestString=""):ThermostatF(PinRele,ReleType,TypeT){
        this->StatusRequestString=StatusRequestString;
        this->Tag=Tag;
        TempIdex=-1;
        invalidCommand=0;
    }
    
    void SendState(byte CurrentTemperature,byte CurrentUmidity){Send(Tag+" T:"+String(CurrentTemperature)+" U:"+String(CurrentUmidity)+' '+Status());}
    
    bool InvalidCommand(){return invalidCommand;}
    
    void ThermostatFunction(byte CurrentTemperature,byte CurrentUmidity,String ReceivedString){
        BasicSerialThermostatF::ThermostatFunction(CurrentTemperature);
        invalidCommand=0;
        if(nTick()){
            TempIdex = ReceivedString.indexOf(Tag+" T=");
            if(ReceivedString==StatusRequestString){SendState(CurrentTemperature,CurrentUmidity);}
            else if(TempIdex>=0){
                TempIdex=TempIdex+Tag.length();
                SetTemperatureThreshold(byte(ReceivedString.substring(TempIdex+4,TempIdex+6)));
            }
            else if(ReceivedString!=""){invalidCommand=1;}
        }
    }
};
#endif
