#include "DefaultSerialThermostatFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultSerialThermostatF T(13,"T",NormalLogic,Heating,"RS",9600);
DefaultBluetoothF B(9600);
void setup(){}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24,30,B.ReadString());
if(T.InvalidCommand()){B.SendLn("INVALID COMMAND");}
}
