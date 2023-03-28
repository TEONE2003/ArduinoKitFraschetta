#include "DefaultSerialRelayFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF BT(9600);
DefaultSerialRelayF LivingRoomLight("LRL",13,NormalLogic,SaveStatus,9600);
void setup(){}
void loop(){
 BT.ReceiveString();
 LivingRoomLight.FunctionSerialRelay(BT.ReadString());
 if(LivingRoomLight.InvalidCommand()){BT.SendLn("INVALID COMMAND");}
}
