#include "DefaultSerialRelayFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialRelayF LivingRoomLight("LRL",13,NormalLogic,SaveStatus,9600);
void setup(){LivingRoomLight.Begin();}
void loop(){
 B.ReceiveString();
 LivingRoomLight.FunctionSerialRelay(B.ReadString());
 if(LivingRoomLight.InvalidCommand()){B.SendLn("INVALID COMMAND: ["+B.ReadString()+']');}
}
