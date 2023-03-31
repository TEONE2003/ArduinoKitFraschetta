#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600); /*it may be necessary to change the speed to 38400, some communicate to 9600 and others to 38400*/
void setup(){}
void loop(){B.SerialBridgeFunction();}
/*
Set up your serial monitor with the following settings:
baud: 9600
Line Ending Characters: Both NL & CR
*/
