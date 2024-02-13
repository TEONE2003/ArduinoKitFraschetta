#include "DefaultSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialPhotocellDuskToDawnF P(B.GetStringAddress(),B.GetReadableAddress(),"P",A0,800,200,1,Seconds,13,NormalLogic,9600);
void setup(){P.Begin();}
void loop(){
B.ReceiveString();
P.SerialPhotocellDuskToDawnFunction();
}
