#ifndef TerminalDriverObjectFraschetta_h
#define TerminalDriverObjectFraschetta_h
class TerminalDriverObjectF{
private: int CountInvalidCommand; String *ReceivedString; int NIndex;
void SendLn(String Command)=0;
protected:
static const String SyncCommand;
static const int TInstanceCounter;
 void SetInvalidCommand(){
  if(ReceivedString!=""){
   CountInvalidCommand+=1;
   if(CountInvalidCommand==TInstanceCounter){SendLn("INVALID COMMAND: ["+ReceivedString+"]");}
  }
 }
 bool CommandFound(String Command){CountInvalidCommand-=1; return Command==ReceivedString;}
 bool ContentCommand(String Command){CountInvalidCommand-=1; NIndex=ReceivedString.indexOf(Command); return NIndex>=0;}
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return ReceivedString.substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 TerminalDriverObjectF(String *ReceivedString){this->TInstanceCounter+=1; this.ReceivedString=ReceivedString; NIndex=-1;}
};
const String TerminalDriverObjectF::SyncCommand="SYNC";
const int TerminalDriverObjectF::TInstanceCounter=0;
#endif
