#include "PhotoresistorFraschetta.h"
PhotoresistorF P(A0,200,800,1,Seconds);
void setup(){pinMode(13,OUTPUT); P.Begin();}
void loop(){digitalWrite(13,P.NoLight());}
