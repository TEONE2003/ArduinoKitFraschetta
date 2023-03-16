#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
class BasicSerialF{
protected:
 String S;
 uint8_t B;
 char C;
 boolean I,SerialBridge;
 uint16_t Baud;
 uint8_t Tx;
 uint8_t Rx;
 virtual void InitializeIfNotInitialized()=0;
 virtual boolean DataPresent()=0;
 virtual String String()=0;
 virtual uint8_t Byte()=0;
 virtual char Char()=0;
public:
 boolean Initialized(){return I;}
 void ReceiveString(){
  InitializeIfNotInitialized();
  if(DataPresent()){S=String();}
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
 BasicSerialF(uint16_t Baud=9600){this->Baud=Baud;}
};
#endif