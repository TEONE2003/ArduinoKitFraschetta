#include "ArduinoKitFraschetta.h"
DEFAULT_SERIAL S(9600);
NE::EEPROM_UINT32_T N(200,0,50,100); //su arduino non funziona la scrittura nei numeri a 64 bit con bitWrite
void setup() {
N.VALORE(16868);
S.INVIA_ANDANDO_A_CAPO(N.VALORE());
}
void loop() {}
