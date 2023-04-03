#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
#include "SerialDriverObjectFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public SerialDriverObjectF,public PhotocellDuskToDawnF{
protected:
 virtual void Send(String s)=0; String StatusRequestString;
 using PhotocellDuskToDawnF::PhotocellDuskToDawnFunction;
 BasicSerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType),SerialDriverObjectF(){
     StatusRequestString=Tag+".S";
 }
public:
    void SendStatus(){
        if(ReadDigitalStatus()){Send("1");}
        else{Send("0");}
    }
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction(); SetReceivedString(ReceivedString);
        if(CommandFound(StatusRequestString)){SendStatus();}
        else{SetInvalidCommand();}
    }
};
#endif
