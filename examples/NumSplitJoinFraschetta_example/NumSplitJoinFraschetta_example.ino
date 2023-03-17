#include "NumSplitJoinFraschetta.h"
uint32_t N=5; //Your Arduino is not working with writing 64-bit numbers using bitWrite
uint8_t A[4];
void setup(){
Serial.begin(9600);
NumSplitJoinF::SplitIntoFourUint32T(N,A);
for(uint8_t n=0;n<=3; n++) {
Serial.println(String(n)+":"+String(A[n])+" ");
}
uint32_t N2=NumSplitJoinF::JoinUint32T(A[0],A[1],A[2],A[3]);
Serial.println(String("UNITED:")+String(N2));
}
void loop(){}
