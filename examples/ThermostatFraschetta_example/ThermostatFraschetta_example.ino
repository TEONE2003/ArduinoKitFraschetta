#include "ThermostatFraschetta.h"
ThermostatF T(13,NormalLogic,Heating);
void setup(){T.Begin(); T.TurnOn();}
void loop(){T.ThermostatFunction(24);}
