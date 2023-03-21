#ifndef SerialRelayFraschetta_h
#define SerialRelayFraschetta_h
#include "RelayFraschetta.h"
#include "DefaultSerialFraschetta.h"
#include "SerialFraschetta.h"
class BasicSerialRelay:public RelayF{
protected: String TurnOnString,TurnOffString;
public:
 BasicSerialRelay(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):RelayF(Pin,Type,Save){
     TurnOnString=Tag+'1'; TurnOffString=Tag+'0';
 }
 virtual void Send(String s)=0
 void FuncionSerialRelay(String ReceivedString){
  if(ReceivedString == TurnOnString){Send(TurnOnString);}
  else if(ReceivedString == TurnOffString){Send(TurnOffString);}
 }
};

class SerialRelayF:SerialF,public BasicSerialRelay{
public:
 SerialRelayF(){}
 SerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint8_t RX=2,uint8_t TX=3,uint32_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):
  SerialF(,Baud){}
 void Send(String s)override{SerialF:Send(s);}
};

class DefaultSerialRelayF:DefaultSerialF,public BasicSerialRelay{
public:
 DefaultSerialRelayF(){}
 DefaultSerialRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):DefaultSerialF(Baud){}
 void Send(String s)override{DefaultSerialF:Send(s);}
};

class DefaultSerial1RelayF:DefaultSerial1F,public BasicSerialRelay{
public:
 DefaultSerial1RelayF(){}
 DefaultSerial1RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):DefaultSerial1F(Baud){}
 void Send(String s)override{DefaultSerial1F:Send(s);}
};

class DefaultSerial2RelayF:DefaultSerial2F,public BasicSerialRelay{
public:
 DefaultSerial1RelayF(){}
 DefaultSerial1RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):DefaultSerial2F(Baud){}
 void Send(String s)override{DefaultSerial2F:Send(s);}
};

class DefaultSerial3RelayF:DefaultSerial3F,public BasicSerialRelay{
public:
 DefaultSerial3RelayF(){}
 DefaultSerial3RelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,uint16_t Baud=9600):BasicSerialRelay(Pin,Tag,Type,Save):DefaultSerial3F(Baud){}
 void Send(String s)override{DefaultSerial3F:Send(s);}
};
#endif
