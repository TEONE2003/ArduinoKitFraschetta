#include "ArduinoKitFraschetta.h"
CRONOMETRO C(MILLISECONDI);
void setup(){
Serial.begin(9600);
C.AVVIA();
delay(500);
Serial.println(uint32_t(C.TEMPO_PASSATO().VALORE));
C.STOPPA();
}
void loop(){}
