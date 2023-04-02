#include "PhotoresistorFraschetta.h"
PhotoresistorF P(A0,800,200,1,Seconds);
void setup(){pinMode(13,OUTPUT); P.Begin();}
void loop(){digitalWrite(13,P.Check());}
