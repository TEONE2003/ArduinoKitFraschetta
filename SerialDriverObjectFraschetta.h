#ifndef SerialDriverObjectFraschettaa_h
#define SerialDriverObjectFraschetta_h
class SerialDriverObjectF{
private: bool invalidCommand; String ReceivedString;
protected:
 virtual void Send(String s)=0;
 void SetReceivedString(String ReceivedString){this->ReceivedString=ReceivedString;}
 void SetInvalidCommand(){if(ReceivedString!=""){invalidCommand=1;}}
 void ResetInvalidCommand(){invalidCommand=0;}
 bool CommandFound(String Command){return ReceivedString.indexOf(Command)>=0;}
public:
 SerialDriverObjectF(){invalidCommand=0;}
 bool InvalidCommand(){return invalidCommand;}
};
#endif
