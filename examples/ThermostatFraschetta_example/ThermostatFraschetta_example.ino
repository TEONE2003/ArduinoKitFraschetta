#include "ThermostatFraschetta.h"
ThermostatF T(13,NormalLogic,Heating);
void setup(){T.Begin();}
void loop(){
T.ThermostatFunction(24);
}
