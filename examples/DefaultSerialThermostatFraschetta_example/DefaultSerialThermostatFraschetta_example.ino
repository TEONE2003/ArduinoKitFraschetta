#include "DefaultSerialThermostatFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialThermostatF T(B.GetStringAddress(),B.GetReadableAddress(),"T",13,NormalLogic,Heating,9600);
void setup(){T.Begin();}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24);
}
