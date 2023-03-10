#include "ArduinoKitFraschetta.h"
CICLO_TIMER C(2,SECONDI);
LED L(13);
void setup(){pinMode(13,OUTPUT);}
void loop(){if(C.TICK()){L.INVERTI_STATO();}}
