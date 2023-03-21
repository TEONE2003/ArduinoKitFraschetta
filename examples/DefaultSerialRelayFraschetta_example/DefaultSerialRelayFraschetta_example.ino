#include "DefualtSerialRelayFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF BT(9600);
DefualtSerialRelayF LivingRoomLight(13,"LRL",NormalLogic,SaveStatus,9600);
void setup(){}
void loop(){
 BT.ReceiveString();
 LivingRoomLight.FunctionSerialRelay(BT.string());
}
