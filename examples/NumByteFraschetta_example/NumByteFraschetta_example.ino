#include "NumByteFraschetta.h"
uint32_t N=78687999; //Your Arduino Uno is not working with writing to 64-bit numbers using bitWrite.
uint8_t A[4]={230,100,255,80};

void VisualizeByteNumber(){
for(uint8_t n=0;n<=3;n++){
Serial.print(String(n)+":"+String(NumByteF::ReadByte(n,N))+" ");
}
Serial.print("\n");
}

void setup(){
Serial.begin(9600);
VisualizeByteNumber();
for(uint8_t n=0; n<=3; n++){
NumByteF::WriteByte(n, N, A[n]);
}
VisualizeByteNumber();
}

void loop(){}
