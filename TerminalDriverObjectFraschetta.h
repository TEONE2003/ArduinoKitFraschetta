#ifndef TerminalDriverObjectFraschetta_h
#define TerminalDriverObjectFraschetta_h
class TerminalDriverObjectF{
private: String *ReceivedString; int NIndex; bool Subscribe; static const String IC1; static const char IC2;
virtual void SendLn(String Command)=0;
protected:
static const String SyncCommand;
static int InstanceCounter;
static int CountInvalidCommand;
static bool Readable;
 void SetInvalidCommand(){
   if(Subscribe){CountInvalidCommand+=1; Subscribe=0;} 
   if(CountInvalidCommand==InstanceCounter) SendLn(IC1+ (*ReceivedString) +IC2);
 }
 bool CommandFound(String Command){if(Readable){Subscribe=1; return Command == *ReceivedString;} return false;}
 bool ContentCommand(String Command){if(Readable){Subscribe=1; NIndex= (*ReceivedString).indexOf(Command); return NIndex>=0;} return false;}
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return (*ReceivedString).substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 TerminalDriverObjectF(String *ReceivedString){
    TerminalDriverObjectF::InstanceCounter+=1;
    this->ReceivedString=ReceivedString; NIndex=-1; Subscribe=false;}
};
const String TerminalDriverObjectF::SyncCommand="SYNC";
const String TerminalDriverObjectF::IC1="INVALID COMMAND: [";
const char TerminalDriverObjectF::IC2=']';
int TerminalDriverObjectF::InstanceCounter=0;
int TerminalDriverObjectF::CountInvalidCommand=0;
bool TerminalDriverObjectF::Readable=false;
#endif
