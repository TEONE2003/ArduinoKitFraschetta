#include "SerialRelayFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF BT(2,3,9600);
SerialRelayF LivingRoomLight(13,"LRL",NormalLogic,SaveStatus,"SR",2,3,9600);
void setup(){}
void loop(){
 BT.ReceiveString();
 LivingRoomLight.FunctionSerialRelay(BT.ReadString());
}
