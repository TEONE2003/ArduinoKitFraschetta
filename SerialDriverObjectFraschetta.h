#ifndef SerialDriverObjectFraschetta_h
#define SerialDriverObjectFraschetta_h
class SerialDriverObjectF{
private: bool invalidCommand; String ReceivedString; int NIndex;
protected:
 const String SyncCommand="SYNC";
 void SetReceivedString(String ReceivedString){this->ReceivedString=ReceivedString;}
 void SetInvalidCommand(){if(ReceivedString!=""){invalidCommand=1;}}
 bool CommandFound(String Command){invalidCommand=0; return Command==ReceivedString;}
 bool ContentCommand(String Command){invalidCommand=0; NIndex=ReceivedString.indexOf(Command); return NIndex>=0;}
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return ReceivedString.substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 SerialDriverObjectF(){invalidCommand=0; ReceivedString=""; NIndex=-1;}
public: bool InvalidCommand(){return invalidCommand;}
};
#endif
