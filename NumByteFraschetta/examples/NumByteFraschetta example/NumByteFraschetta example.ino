#include "ArduinoKitFraschetta.h"
DEFAULT_SERIAL S(9600);
uint32_t N=78687999; //su arduino non funziona la scrittura nei numeri a 64 bit con bitWrite
uint8_t A[4]={230,100,255,80};

void VISUALIZZA_BYTE_NUMERO(){
for(uint8_t n=0;n<=3;n++){
S.INVIA(String(n)+":"+String(LSBDN::LEGGI_BYTE(n,N))+" ");
}
S.INVIA("\n");
}

void setup(){
VISUALIZZA_BYTE_NUMERO();

for(uint8_t n=0; n<=3; n++){
LSBDN::SCRIVI_BYTE(n, N, A[n]);
}

VISUALIZZA_BYTE_NUMERO();
}

void loop(){}
