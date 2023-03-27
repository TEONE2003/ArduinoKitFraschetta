#ifndef BasicSerialPhotocellDuskToDawnFraschetta_h
#define BasicSerialPhotocellDuskToDawnFraschetta_h
#include "PhotocellDuskToDawnFraschetta.h"
class BasicSerialPhotocellDuskToDawnF:public PhotocellDuskToDawnFraschetta{
protected:
 virtual void Send(String s)=0; String StatusRequestString; bool invalidCommand;
  String Status(){
   if(ReadDigitalStatus()){return "1";}
    else{return "0";}
  }
public:
 PhotocellDuskToDawnF(String Tag,String StatusRequestString,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):PhotocellDuskToDawnFraschetta(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType){
     this->Tag=Tag;
     this->StatusRequestString=StatusRequestString;
     invalidCommand=0;
 }
    bool InvalidCommand(){return invalidCommand;}
    void SendState(){Send(Tag+" S:"+Status());}
    void SerialPhotocellDuskToDawnFunction(String ReceivedString){
        PhotocellDuskToDawnFunction();
        invalidCommand=0;
        if(ReceivedString==StatusRequestString){SendState();}
        else if(ReceivedString!=""){invalidCommand=1;}
    }
};
#endif
