#include "SerialThermostatFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialThermostatF T("T",13,NormalLogic,Heating,2,3,9600,B.GetStringAddress());
void setup(){T.Begin();}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24);
}
