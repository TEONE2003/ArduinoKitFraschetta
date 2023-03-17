#ifndef AtCommands_h
#define AtCommands_h
enum Role{Slave,Master};
class AtCommands{
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
#endif
