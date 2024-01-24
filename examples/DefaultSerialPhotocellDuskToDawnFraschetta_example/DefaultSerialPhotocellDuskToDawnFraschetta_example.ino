#include "DefaultSerialPhotocellDuskToDawnFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialPhotocellDuskToDawnF P("P",A0,800,200,1,Seconds,13,NormalLogic,9600,B.GetStringAddress());
void setup(){P.Begin();}
void loop(){
B.ReceiveString();
P.SerialPhotocellDuskToDawnFunction();
}
