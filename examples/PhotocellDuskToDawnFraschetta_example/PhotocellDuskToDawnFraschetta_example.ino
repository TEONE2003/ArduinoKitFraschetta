#include "PhotocellDuskToDawnFraschetta.h"
PhotocellDuskToDawnF C(A0,800,200,1,Seconds,13,NormalLogic);
void setup(){C.Begin();}
void loop(){
C.PhotocellDuskToDawnFunction();
}
