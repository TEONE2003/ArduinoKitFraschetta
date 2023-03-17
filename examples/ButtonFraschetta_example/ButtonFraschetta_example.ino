#include "ButtonFraschetta.h"
ButtonF B(13,NormalLogic);
void setup(){Serial.begin(9600);}
void loop(){if(B.Clicked()){Serial.println("Clicked");}}
