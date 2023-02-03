#include "ArduinoKitFraschetta.h"
DEFAULT_SERIAL S(9600);
uint64_t N=8000;
uint8_t A[8]={230,100,50,80,255,255,60,100};

void VISUALIZZA_BYTE_NUMERO(){
for(uint8_t n=0;n<=7;n++){
S.INVIA(String(n)+":"+String(LSBDN::LEGGI_BYTE(n,N))+" ");
}
S.INVIA("\n");
}

void setup() {
VISUALIZZA_BYTE_NUMERO();
/*LSBDN::SCRIVI_BYTE(0, N, 230);
LSBDN::SCRIVI_BYTE(1, N, 80);
LSBDN::SCRIVI_BYTE(2, N, 90);
LSBDN::SCRIVI_BYTE(3, N, 100);
LSBDN::SCRIVI_BYTE(4, N, 70);
LSBDN::SCRIVI_BYTE(5, N, 90);
LSBDN::SCRIVI_BYTE(6, N, 40);
LSBDN::SCRIVI_BYTE(7, N, 230);*/
for(uint8_t n=0; n<=7; n++){
LSBDN::SCRIVI_BYTE(n, N, A[n]);
S.INVIA_ANDANDO_A_CAPO(A[n]);
}
VISUALIZZA_BYTE_NUMERO();
}
void loop(){}
