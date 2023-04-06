#ifndef SerialDriverObjectFraschetta_h
#define SerialDriverObjectFraschetta_h
class SerialDriverObjectF{
private: bool invalidCommand; String ReceivedString;
protected:
 void SetReceivedString(String ReceivedString){this->ReceivedString=ReceivedString;}
 void SetInvalidCommand(){if(ReceivedString!=""){invalidCommand=1;}}
 bool CommandFound(String Command){invalidCommand=0; return Command==ReceivedString;}
 SerialDriverObjectF(){invalidCommand=0;}
public: bool InvalidCommand(){return invalidCommand;}
};
#endif
