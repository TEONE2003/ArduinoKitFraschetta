#include "DefaultSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultSerialPhotocellDuskToDawnF P("P","RS",A0,800,200,1,Seconds,13,NormalLogic,9600);
DefaultBluetoothF B(9600);
void setup(){}
void loop(){
B.ReceiveString();
P.SerialPhotocellDuskToDawnFunction(B.ReadString());
}