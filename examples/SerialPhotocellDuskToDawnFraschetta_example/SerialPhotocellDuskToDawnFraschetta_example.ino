#include "SerialPhotocellDuskToDawnFraschetta.h"
#include "BluetoothFraschetta.h"
SerialPhotocellDuskToDawnF P("P","RS",A0,800,200,1,Seconds,13,NormalLogic,2,3,9600);
BluetoothF B(2,3,9600);
void setup(){}
void loop(){
B.ReceiveString();
P.SerialPhotocellDuskToDawnFunction(B.ReadString());
}