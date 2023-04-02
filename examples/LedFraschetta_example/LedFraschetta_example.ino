#include "LedFraschetta.h"
LedF L(13);
void setup(){L.Begin();}
void loop(){
L.InvertStatus();
delay(1000);
}
