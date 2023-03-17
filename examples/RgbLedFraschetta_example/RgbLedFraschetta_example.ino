#include "RgbLedFraschetta.h"
RgbLedF L(2,3,4,SaveStatus,RedColor);
void setup(){}
void loop(){
L.Blink(1,Seconds);
}
