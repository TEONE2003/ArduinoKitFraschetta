#ifndef TerminalDriverObjectFraschetta_h
#define TerminalDriverObjectFraschetta_h
class TerminalDriverObjectF{
private: String *ReceivedString; int NIndex; bool Subscribe;
void SendLn(String Command)=0;
protected:
static const String SyncCommand;
static const int InstanceCounter;
static const int CountInvalidCommand;
 void SetInvalidCommand(){
  if(*ReceivedString!=""){
  if(Subscribe){CountInvalidCommand+=1; Subscribe=0;} 
  if(CountInvalidCommand==InstanceCounter) SendLn("INVALID COMMAND: ["+ *ReceivedString +"]");
  }
 }
 bool CommandFound(String Command){Subscribe=1; return Command == *ReceivedString;}
 bool ContentCommand(String Command){Subscribe=1; NIndex= *ReceivedString.indexOf(Command); return NIndex>=0;}
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return *ReceivedString.substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 TerminalDriverObjectF(String *ReceivedString){this->InstanceCounter+=1; this.ReceivedString=ReceivedString; NIndex=-1; Subscribe=false;}
};
const String TerminalDriverObjectF::SyncCommand="SYNC";
const int TerminalDriverObjectF::InstanceCounter=0;
const int TerminalDriverObjectF::CountInvalidCommand=0;
#endif
