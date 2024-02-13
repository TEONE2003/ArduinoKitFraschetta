#include "DefaultSerialRelayFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialRelayF LivingRoomLight(B.GetStringAddress(),B.GetReadableAddress(),"LRL",13,NormalLogic,SaveStatus,9600);
void setup(){LivingRoomLight.Begin();}
void loop(){
 B.ReceiveString();
 LivingRoomLight.FunctionSerialRelay();
}
