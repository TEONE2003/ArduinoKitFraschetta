#include "PhotoresistorFraschetta.h"
PhotoresistorF F1(A0,800,200,1,Seconds);
void setup(){pinMode(13,OUTPUT);}
void loop(){digitalWrite(13,F1.Check());}
