#include "SerialRelayFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF BT(2,3,9600);
SerialRelayF LivingRoomLight("LRL",13,NormalLogic,SaveStatus,2,3,9600);
void setup(){LivingRoomLight.Begin();}
void loop(){
 BT.ReceiveString();
 LivingRoomLight.FunctionSerialRelay(BT.ReadString());
 if(LivingRoomLight.InvalidCommand()){BT.SendLn("INVALID COMMAND");}
}
