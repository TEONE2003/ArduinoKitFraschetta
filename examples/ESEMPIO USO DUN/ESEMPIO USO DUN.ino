#include "ArduinoKitFraschetta.h"
DEFAULT_SERIAL S(9600);
uint32_t N=5; //su arduino non funziona la scrittura nei numeri a 64 bit con bitWrite
uint8_t A[4];
void setup(){
DUN::DIVIDI_IN_QUATTRO_UINT32_T(N,A);

for(uint8_t n=0;n<=3; n++) {
S.INVIA(String(n)+":"+String(A[n])+" ");
}
S.INVIA("\n");

uint32_t N2=DUN::UNISCI_UINT32_T(A[0],A[1],A[2],A[3]);
S.INVIA_ANDANDO_A_CAPO(String("UNITO:")+String(N2));
}
void loop(){}
