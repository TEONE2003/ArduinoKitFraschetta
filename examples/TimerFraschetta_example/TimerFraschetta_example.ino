#include "TimerFraschetta.h"
TimerF T(1,Seconds);
void setup(){pinMode(13,OUTPUT);}
void loop(){
if(T.Stop()){
digitalWrite(13,!digitalRead(13));
T.Enable();
}
}