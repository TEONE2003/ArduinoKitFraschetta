#include "ThermostatFraschetta.h"
ThermostatF T(13,NormalLogic,Heating);
void setup(){}
void loop(){
T.ThermostatFunction(24);
}
