#ifndef TerminalDriverObjectFraschetta_h
#define TerminalDriverObjectFraschetta_h
class TerminalDriverObjectF{
private:  int NIndex; bool Subscribe; static const String IC;
virtual void Send(String s)=0;
protected:
String *ReceivedString;
bool *Readable;
static const String SyncCommand;
static int InstanceCounter;
static int CountInvalidCommand;
 void SetInvalidCommand(){
  if(*Readable){
   if(Subscribe){Subscribe=false; CountInvalidCommand+=1;}
   if(CountInvalidCommand==InstanceCounter) {*Readable=false; Subscribe=true; Send(IC+ (*ReceivedString) + char(93)); CountInvalidCommand=0;}
   }
  }
 bool CommandFound(const String &Command){
    if(*Readable && Command == *ReceivedString) {*Readable=false; CountInvalidCommand=0; return 1;}
     return false;
    }
 bool ContentCommand(const String &Command){
    if(*Readable && (*ReceivedString).indexOf(Command)>=0){*Readable=false; CountInvalidCommand=0; return 1;}
     return false;
  }
 int ExtractNumber(int TagLength,uint8_t NumberDigits){NIndex+=TagLength; return (*ReceivedString).substring(NIndex+1,NIndex+NumberDigits+1).toInt();}
 TerminalDriverObjectF(String *ReceivedString,bool *Readable){
    TerminalDriverObjectF::InstanceCounter+=1; this->Readable=Readable;
    this->ReceivedString=ReceivedString; NIndex=-1; Subscribe=true;
    }
};
const String TerminalDriverObjectF::SyncCommand="SYNC";
const String TerminalDriverObjectF::IC="INVALID COMMAND: [";
int TerminalDriverObjectF::InstanceCounter=0;
int TerminalDriverObjectF::CountInvalidCommand=0;
#endif
