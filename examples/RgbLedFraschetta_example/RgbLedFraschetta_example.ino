#include "RgbLedFraschetta.h"
RgbLedF L(2,3,4,SaveStatus,RedColor);
void setup(){L.Begin();}
void loop(){L.Blink(1,Seconds);}
