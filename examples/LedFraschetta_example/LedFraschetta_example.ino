#include "LedFraschetta.h"
LedF L(13);
void setup(){}
void loop(){
L.InvertStatus();
delay(1000);
}
