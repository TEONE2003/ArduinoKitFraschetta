#ifndef TerminalDriverObjectFraschetta_h
#define TerminalDriverObjectFraschetta_h
class TerminalDriverObjectF{
private: bool invalidCommand; String *ReceivedString; int NIndex;
protected:
static const String SyncCommand;
 void SetInvalidCommand(){if(ReceivedString!=""){invalidCommand=1;}}
 bool CommandFound(String Command){invalidCommand=0; return Command==ReceivedString;}
 bool ContentCommand(String Command){invalidCommand=0; NIndex=ReceivedString.indexOf(Command); return NIndex>=0;}
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return ReceivedString.substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 TerminalDriverObjectF(String *ReceivedString){invalidCommand=0; this.ReceivedString=ReceivedString; NIndex=-1;}
public: bool InvalidCommand(){return invalidCommand;}
};
const String TerminalDriverObjectF::SyncCommand="SYNC";
#endif
