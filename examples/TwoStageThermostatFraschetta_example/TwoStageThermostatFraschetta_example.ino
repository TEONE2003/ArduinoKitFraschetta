#include "TwoStageThermostatFraschetta.h"
TwoStageThermostatF TST(2,3,NormalLogic);
void setup(){TST.Begin();}
void loop(){TST.TwoStageThermostatFunction(24);}
