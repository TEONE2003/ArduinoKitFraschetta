#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "SerialDriverObjectFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public SerialDriverObjectF,public PhotocellDuskToDawnF{
protected:
 virtual void Send(String s)=0; String OnString,OffString,StatusRequest,InvertStatusString,RelayStatusString,BypassString,InvertBypassString,BypassOnString,BypassOffString,LightRequest;
 using PhotocellDuskToDawnF::PhotocellDuskToDawnFunction;
 BasicSerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),SerialDriverObjectF(){
    OnString=Tag+"=1"; OffString=Tag+"=0"; StatusRequest=Tag+".S"; InvertStatusString=Tag+".I"; RelayStatusString=Tag+".RS"; BypassString=Tag+".B"; InvertBypassString=Tag+".IB";
    BypassOnString=Tag+".B=1"; BypassOffString=Tag+".B=0"; LightRequest=Tag+".L";
 }
public:
    void SendRelayStatus(){if(StatusRelay()){Send(RelayStatusString+"=1");}else{Send(RelayStatusString+"=0");}}
    void SendBypassStatus(){if(bypass){Send(BypassOnString);}else{Send(BypassOffString);}}
    void SendStatus(){if(active){Send(OnString);} else{Send(OffString);}}
    void SendLightStatus(){Send(LightRequest+"="+String(Light()));}
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction(); SetReceivedString(ReceivedString);
        if(CommandFound(RelayStatusString)){SendRelayStatus();}
        else if(CommandFound(LightRequest)){SendLightStatus();}
        else if(CommandFound(BypassString)){SendBypassStatus();}
        else if(CommandFound(InvertBypassString)){InvertBypass(); SendBypassStatus();}
        else if(CommandFound(BypassOnString)){BypassOn(); SendBypassStatus();}
        else if(CommandFound(BypassOffString)){BypassOff(); SendBypassStatus();}
        else if(CommandFound(OnString)){On(); SendStatus();}
        else if(CommandFound(OffString)){Off(); SendStatus();}
        else if(CommandFound(InvertStatusString)){InvertStatus(); SendStatus();}
        else if(CommandFound(StatusRequest)){SendStatus();}
        else if(CommandFound(SyncCommand)){SendStatus(); SendRelayStatus(); SendBypassStatus(); SendLightStatus();}
        else{SetInvalidCommand();}
        if(LightChanged()){SendLightStatus();}
        if(RelayChanged()){SendRelayStatus();}
    }
};
#endif
