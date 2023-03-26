#include "SerialThermostatFraschetta.h"
#include "BluetoothFraschetta.h"
SerialThermostatF T(13,"T",NormalLogic,Heating,"RS",2,3,9600);
BluetoothF B(2,3,9600);
void setup(){}
void loop(){
B.ReceiveString();
T.SerialThermostatFunction(24,30,B.ReadString());
if(T.InvalidCommand()){B.SendLn("INVALID COMMAND");}
}
