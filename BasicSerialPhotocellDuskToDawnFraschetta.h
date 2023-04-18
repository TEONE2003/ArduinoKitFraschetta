#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "SerialDriverObjectFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public SerialDriverObjectF,public PhotocellDuskToDawnF{
protected:
 virtual void Send(String s)=0; String StatusRequestString,BypassString,InvertBypassString,BypassOnString,BypassOffString;
 using PhotocellDuskToDawnF::PhotocellDuskToDawnFunction;
 BasicSerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),SerialDriverObjectF(){
     StatusRequestString=Tag+".S"; BypassString=Tag+".B"; InvertBypassString=Tag+".IB"; BypassOnString=Tag+".B=1"; BypassOffString=Tag+".B=0";
 }
public:
    void SendStatus(){if(ReadDigitalStatus()){Send(StatusRequestString+"=1");}else{Send(StatusRequestString+"=0");}}
    void SendStatusBypass(){if(Bypass){Send(BypassOnString);}else{Send(BypassOffString);}}
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction(); SetReceivedString(ReceivedString);
        if(CommandFound(StatusRequestString)){SendStatus();}
        else if(CommandFound(BypassString)){SendStatusBypass();}
        else if(CommandFound(InvertBypassString)){InvertBypass(); SendStatusBypass();}
        else if(CommandFound(BypassOnString)){BypassOn(); SendStatusBypass();}
        else if(CommandFound(BypassOffString)){BypassOff(); SendStatusBypass();}
        else{SetInvalidCommand();}
        if(RelayChanged()){SendStatus();}
    }
};
#endif
