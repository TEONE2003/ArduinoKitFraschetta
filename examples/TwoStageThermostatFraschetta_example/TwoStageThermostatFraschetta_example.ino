#include "TwoStageThermostatFraschetta.h"
TwoStageThermostatF TST(2,3,NormalLogic);
void setup(){}
void loop(){TST.ThermostatFunction(24);}
