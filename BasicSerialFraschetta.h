#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
class BasicSerialF{
private:
  String S; uint8_t B; char C; bool R;
  virtual uint8_t SerialRead()=0;
  virtual bool DataPresent()=0;
  virtual void SendLn(String S)=0;
  String string(){return String(char(SerialRead()));}
  uint8_t Byte(){return SerialRead();}
  char Char(){return SerialRead();}
protected:
 BasicSerialF(){S=""; B=0; C='_'; R=false;}
public:
 virtual void SetBaudRate(long Baud)=0;
 void ReceiveString(){
  S="";
  if(DataPresent()){
   int Index=-1;
   while(Index<0){if(DataPresent()){S=S+string(); Index=S.indexOf(char(uint8_t(10)));}}
   S=S.substring(0,Index);
   R=true;
  }
 }
 void ReceiveByte(){
  if(DataPresent()){B=Byte(); R=true;}
  else{B=0;}
 }
 void ReceiveChar(){
  if(DataPresent()){C=Char(); R=true;}
  else{C=0;}
}
 String ReadString(){R=false; return S;}
 String* GetStringAddress(){return &S;}
 uint8_t ReadByte(){R=false; return B;}
 char ReadChar(){R=false; return C;}
 bool Readible(){return R;}
};
#endif
