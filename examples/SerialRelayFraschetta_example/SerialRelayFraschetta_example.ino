#include "SerialRelayFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialRelayF LivingRoomLight(B.GetStringAddress(),B.GetReadableAddress(),"LRL",13,NormalLogic,SaveStatus,2,3,9600);
void setup(){LivingRoomLight.Begin();}
void loop(){
 B.ReceiveString();
 LivingRoomLight.FunctionSerialRelay();
}
