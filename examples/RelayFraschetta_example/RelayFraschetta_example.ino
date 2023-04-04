#include "RelayFraschetta.h"
RelayF LivingRoomLight(13,NormalLogic);
void setup(){LivingRoomLight.Begin();}
void loop(){
Wait(1,Seconds);
LivingRoomLight.TurnOn();
Wait(1,Seconds);
LivingRoomLight.TurnOff();
}
