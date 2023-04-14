#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
class BasicSerialF{
private:
  String S; uint8_t B;
  char C; bool I;
  long Baud;
  virtual uint8_t SerialRead()=0;
  virtual void SerialEnd()=0;
  virtual void SerialBegin(long Baud)=0;
  virtual bool DataPresent()=0;
  String string(){return String(char(SerialRead()));}
  uint8_t Byte(){return SerialRead();}
  char Char(){return SerialRead();}
 public: boolean Initialized(){return I;}
 protected:
  void InitializeIfNotInitialized(){if(!Initialized()){SerialEnd(); SerialBegin(Baud); I=1;}}
  BasicSerialF(long Baud=9600){this->Baud=Baud; S=""; B=0;}
public:
 void ReceiveString(){
  InitializeIfNotInitialized();
  if(DataPresent()){
   int Index=-1;
   while(Index<0){if(DataPresent()){S=S+string(); Index=S.indexOf("\n");}}
   S=S.substring(0,Index);
  }
  else{S="";}
 }
 void ReceiveByte(){
  InitializeIfNotInitialized();
  if(DataPresent()){B=Byte();}
  else{B=0;}
 }
 void ReceiveChar(){
  InitializeIfNotInitialized();
  if(DataPresent()){C=Char();}
  else{C=0;}
}
 String ReadString(){return S;}
 uint8_t ReadByte(){return B;}
 char ReadChar(){return C;}
};
#endif
