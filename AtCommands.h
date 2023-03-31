#ifndef AtCommands_h
#define AtCommands_h
enum Role{Slave,Master};
class AtCommands{
protected:
 virtual void ReceiveString()=0;
 virtual String ReadString()=0;
 virtual void Send(String s)=0;
 const String NlCr="\r\n";
 bool WaitOk(){
  while(ReadString().indexOf("OK")<0){ReceiveString();}
  ReceiveString();
  return 1;
 }
public:
 bool ModeAt(){Send("AT"+NlCr); return WaitOk();}
 String AtName(){
  while(!ModeAt()){}
  Send("AT+NAME?"+NlCr);
  while(ReadString()==""){ReceiveString();}
  String RS=ReadString().substring(6,ReadString().length()-6);
  ReceiveString();
  return RS;
 }
 bool AtUart(){
  
 }
 bool AtRole(){
  while(!ModeAt()){}
  Send("AT+ROLE?"+NlCr);
  while(ReadString()==""){ReceiveString();}
  String RS=ReadString();
  ReceiveString();
  return RS.indexOf('1')>=0;
 }
 bool AtRole(Role R){
  while(!ModeAt()){}
  if(R==Master){Send("AT+ROLE1"+NlCr);}
  else{Send("AT+ROLE0"+NlCr);}
  return AtRole();
 }
 bool AtResetSettings(){while(!ModeAt()){} Send("AT+RESET"+NlCr); return WaitOk();}
 bool AtName(String Name){while(!ModeAt()){} Send("AT+NAME="+Name+NlCr); return Name==AtName();}
 bool AtUart(uint8_t Baud){ while(!ModeAt()){} Send("AT+UART="+String(Baud)+",0,0"+NlCr); return WaitOk();}
 bool AtAssociate(uint8_t MacAddress){ while(!ModeAt()){} Send("AT+BIND="+String(MacAddress)+NlCr); return WaitOk();}
};
#endif
