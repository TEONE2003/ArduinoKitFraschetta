#include "SerialThermostatFraschetta.h"
#include "BluetoothFraschetta.h"
SerialThermostatF T("T",13,NormalLogic,Heating,2,3,9600);
BluetoothF B(2,3,9600);
void setup(){}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24,B.ReadString());
if(T.InvalidCommand()){B.SendLn("INVALID COMMAND");}
}
