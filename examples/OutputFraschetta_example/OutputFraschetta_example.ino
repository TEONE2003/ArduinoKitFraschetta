#include "OutputFraschetta.h"
OutputF O(13);
void setup(){O.Begin();}
void loop(){
O.InvertStatus();
Wait(1,Seconds);
}
