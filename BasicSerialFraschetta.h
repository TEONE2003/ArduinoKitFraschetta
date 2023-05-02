#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
class BasicSerialF{
private:
  String S; uint8_t B; char C;
  virtual void SerialBegin(long Baud)=0;
  virtual uint8_t SerialRead()=0;
  virtual bool DataPresent()=0;
  virtual void SendLn(String S)=0;
  String string(){return String(char(SerialRead()));}
  uint8_t Byte(){return SerialRead();}
  char Char(){return SerialRead();}
 protected:
  long Baud;
  BasicSerialF(long Baud=9600){this->Baud=Baud; S=""; B=0; C='_';}
public:
 void Begin(){SerialBegin(Baud);}
 void ReceiveString(){
  if(DataPresent()){
   int Index=-1;
   while(Index<0){if(DataPresent()){S=S+string(); Index=S.indexOf("\n");}}
   S=S.substring(0,Index);
  }
  else{S="";}
 }
 void ReceiveByte(){
  if(DataPresent()){B=Byte();}
  else{B=0;}
 }
 void ReceiveChar(){
  if(DataPresent()){C=Char();}
  else{C=0;}
}
 String ReadString(){return S;}
 uint8_t ReadByte(){return B;}
 char ReadChar(){return C;}
 void HandleInvalidCommands(bool AllInvalidCommand){if(AllInvalidCommand){SendLn("INVALID COMMAND: ["+ReadString()+"]");}}
};
#endif