#include "ArduinoKitFraschetta.h"
MOTORE_STEPPER_4_BOBINE M(200,30,2,3,4,5);
void setup(){
M.PASSI(100);
}
void loop(){
/*delay(1000);
M.SWIPE_AVANTI();
delay(1000);
M.SWIPE_INDIETRO();*/
}
