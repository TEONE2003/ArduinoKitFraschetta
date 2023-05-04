#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "SerialDriverObjectFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public SerialDriverObjectF,public PhotocellDuskToDawnF{
protected:
 virtual void Send(String s)=0; String RelayStatusString,BypassString,InvertBypassString,BypassOnString,BypassOffString,LightRequest;
 using PhotocellDuskToDawnF::PhotocellDuskToDawnFunction;
 BasicSerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),SerialDriverObjectF(){
     RelayStatusString=Tag+".S"; BypassString=Tag+".B"; InvertBypassString=Tag+".IB"; BypassOnString=Tag+".B=1"; BypassOffString=Tag+".B=0"; LightRequest=Tag+".L";
 }
public:
    void SendRelayStatus(){if(ReadDigitalStatus()){Send(RelayStatusString+"=1");}else{Send(RelayStatusString+"=0");}}
    void SendBypassStatus(){if(Bypass){Send(BypassOnString);}else{Send(BypassOffString);}}
    void SendLightStatus(){Send(LightRequest+"="+String(StatusLight()));}
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction(); SetReceivedString(ReceivedString);
        if(CommandFound(RelayStatusString)){SendRelayStatus();}
        else if(CommandFound(LightRequest)){SendLightStatus();}
        else if(CommandFound(BypassString)){SendBypassStatus();}
        else if(CommandFound(InvertBypassString)){InvertBypass(); SendBypassStatus();}
        else if(CommandFound(BypassOnString)){BypassOn(); SendBypassStatus();}
        else if(CommandFound(BypassOffString)){BypassOff(); SendBypassStatus();}
        else if(CommandFound(SyncCommand())){SendRelayStatus(); SendBypassStatus(); SendLightStatus();}
        else{SetInvalidCommand();}
        if(LightChanged()){SendLightStatus();}
        if(RelayChanged()){SendRelayStatus();}
    }
};
#endif
