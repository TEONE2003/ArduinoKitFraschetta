#include "ArduinoKitFraschetta.h"
TIMER T(1,SECONDI);
LED L(13);
void setup(){T.ABILITA();}
void loop(){
if(T.STOP()){
L.INVERTI_STATO();
T.ABILITA();
}
}