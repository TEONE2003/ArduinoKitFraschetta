#include "ArduinoKitFraschetta.h"
MOTORE_STEPPER_BIPOLARE M(2,3,4,5,1024,5);
void setup(){
M.PASSI(1024);
}
void loop(){
delay(1000);
M.SWIPE_AVANTI();
delay(1000);
M.SWIPE_INDIETRO();
}
