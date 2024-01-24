#include "DefaultSerialThermostatFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialThermostatF T("T",13,NormalLogic,Heating,9600);
void setup(){T.Begin();}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24);
}
