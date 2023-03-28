#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public PhotocellDuskToDawnF{
protected:
 virtual void Send(String s)=0; String StatusRequestString; bool invalidCommand;
 using PhotocellDuskToDawnF::PhotocellDuskToDawnFunction;
public:
    BasicSerialPhotocellDuskToDawnF(String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType){
     StatusRequestString=Tag+".S";
     invalidCommand=0;
 }
    bool InvalidCommand(){return invalidCommand;}
    void SendStatus(){
        if(ReadDigitalStatus()){Send("1");}
        else{Send("0");}
    }
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction();
        invalidCommand=0;
        if(ReceivedString==StatusRequestString){SendStatus();}
        else if(ReceivedString!=""){invalidCommand=1;}
    }
};
#endif
