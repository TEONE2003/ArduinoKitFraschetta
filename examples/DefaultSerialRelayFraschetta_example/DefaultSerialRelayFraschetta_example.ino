#include "DefaultSerialRelayFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialRelayF LivingRoomLight("LRL",13,NormalLogic,SaveStatus,9600,B.GetStringAddress());
void setup(){LivingRoomLight.Begin();}
void loop(){
 B.ReceiveString();
 LivingRoomLight.FunctionSerialRelay();
}
