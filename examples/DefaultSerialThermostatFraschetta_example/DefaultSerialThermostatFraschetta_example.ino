#include "DefaultSerialThermostatFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultSerialThermostatF T("T",13,NormalLogic,Heating,9600);
DefaultBluetoothF B(9600);
void setup(){}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24,B.ReadString());
if(T.InvalidCommand()){B.SendLn("INVALID COMMAND");}
}
