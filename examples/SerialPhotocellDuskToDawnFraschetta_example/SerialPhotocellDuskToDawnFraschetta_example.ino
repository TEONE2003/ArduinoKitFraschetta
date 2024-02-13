#include "SerialPhotocellDuskToDawnFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialPhotocellDuskToDawnF P(B.GetStringAddress(),B.GetReadableAddress(),"P",A0,800,200,1,Seconds,13,NormalLogic,2,3,9600);
void setup(){}
void loop(){
B.ReceiveString();
P.SerialPhotocellDuskToDawnFunction();
}
