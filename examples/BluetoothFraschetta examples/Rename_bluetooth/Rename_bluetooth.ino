#include "BluetoothFraschetta.h"
#include "DefaultSerialFraschetta.h"
BluetoothF B(2,3,38400); /*it may be necessary to change the speed to 38400, some communicate to 9600 and others to 38400*/
DefaultSerialF M(9600);
void setup(){}
void loop(){
while(M.ReadString()==""){M.ReceiveString();}
if(B.AtName(M.ReadString())){M.SendLn("OK");} else{M.SendLn("FAILED");}
M.ReceiveString();
}
/*
Set up your serial monitor with the following settings:
baud: 9600
Line Ending Characters: none
*/
