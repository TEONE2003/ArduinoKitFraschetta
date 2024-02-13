#include "SerialThermostatFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialThermostatF T(B.GetStringAddress(),B.GetReadableAddress(),"T",13,NormalLogic,Heating,2,3,9600);
void setup(){T.Begin();}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24);
}
