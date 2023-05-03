#include "BluetoothFraschetta.h"
BluetoothF B(5,4,9600); /*it may be necessary to change the speed to 38400, some communicate to 9600 and others to 38400*/
void setup(){B.Begin();}
void loop(){B.SerialBridgeFunction();}
/*
If you are configuring the bluetooth module then configure your serial monitor with the following settings:
baud: the speed set in the constructor
End of line characters: both NL and CR
*/
