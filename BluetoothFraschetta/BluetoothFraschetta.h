#ifndef BluetoothFraschetta_h
#define BluetoothFraschetta_h
#include <SerialFraschetta.h>
enum Role{Slave,Master};
class At{
protected:
 virtual void ReceiveString()=0;
 virtual String ReadString()=0;
 virtual void Send(String s)=0;
public:
 boolean ModeAt(){
 Send("At");
 while(ReadString()==""){ReceiveString();}
 return ReadString()=="OK";
 }
 void AtResetSettings(){Send("At+RESET");}
 void AtSetName(String Name){Send("At+NAME"+Name);}
 String AtName(){
 Send("At+NAME?");
 while(ReadString()==""){ReceiveString();}
 return ReadString().substring(8,ReadString().length()-8);
 }
 boolean AtRole(){
 Send("At+ROLE?");
 while(ReadString()==""){ReceiveString();}
 return ReadString().indexOf('1')>=0;
 }
 void AtSetRole(Role R){
  if(R==Master){Send("At+ROLE1");}
  else{Send("At+ROLE0");}
  }
  AtSetBaud(uint8_t Baud){Send("At+BAUD"+String(Baud));}
  AtAssociate(uint8_t MacAddress){Send("At+BIND"+String(MacAddress));}
};

class BluetoothF:public SerialF,public At{
public:
 BluetoothF(uint8_t Rx=2,uint8_t Tx=3,uint32_t Baud):SerialF( Rx,Tx,Baud){}
 void ReceiveString()override{SerialF::ReceiveString();}
 String ReadString()override{return SerialF::ReadString();}
 void Send(String s)override{SerialF::Send(s);}
 template <typename T>
 void Send(T t){SerialF::Send(t);}
};

class DefaultBluetoothF:public DefaultSerial,public At{
public:
 DefaultBluetoothF(uint32_t Baud=9600):DefaultSerial(Baud){}
 void ReceiveString()override{DefaultSerial::ReceiveString();}
 String ReadString()override{return DefaultSerial::ReadString();}
 void Send(String s)override{DefaultSerial::Send(s);}
 templAte <typename T>
 void Send(T t){DefaultSerial::Send(t);}
};

#ifdef __AVR_Atmega2560__ || __AVR_Atmega1280__
class Default1BluetoothF:public DefaultSerial1,public At{
public:
 Default1BluetoothF(uint32_t Baud=9600):DefaultSerial1(Baud){}
 void ReceiveString()override{DefaultSerial1::ReceiveString();}
 String ReadString()override{return DefaultSerial1::ReadString();}
 void Send(String s)override{DefaultSerial1::Send(s);}
};

class Default2BluetoothF:public DefaultSerial2,public At{
public:
 Default2BluetoothF(uint32_t Baud=9600):DefaultSerial2(Baud){}
 void ReceiveString()override{DefaultSerial2::ReceiveString();}
 String ReadString()override{return DefaultSerial2::ReadString();}
 void Send(String s)override{DefaultSerial2::Send(s);}
};

class Default3BluetoothF:public DefaultSerial3,public At{
public:
 Default3BluetoothF(uint32_t Baud=9600):DefaultSerial3(Baud){}
 void ReceiveString()override{DefaultSerial3::ReceiveString();}
 String ReadString()override{return DefaultSerial3::ReadString();}
 void Send(String s)override{DefaultSerial3::Send(s);}
};
#endif
#endif
