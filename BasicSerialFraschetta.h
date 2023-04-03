#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
class BasicSerialF{
protected:
 String S;
 uint8_t B;
 char C;
 bool I,SerialBridge;
 uint16_t Baud;
 uint8_t Tx;
 uint8_t Rx;
 virtual void InitializeIfNotInitialized()=0;
 virtual bool DataPresent()=0;
 virtual String string()=0;
 virtual uint8_t Byte()=0;
 virtual char Char()=0;
 BasicSerialF(uint16_t Baud=9600){this->Baud=Baud;}
public:
 boolean Initialized(){return I;}
 void ReceiveString(){
  InitializeIfNotInitialized();
  if(DataPresent()){S=string();}
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
