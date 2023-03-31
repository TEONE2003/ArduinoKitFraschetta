#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
void setup(){}
void loop(){B.SerialBridgeFunction();}
/*
Set up your serial monitor with the following settings:
baud: 9600
Line Ending Characters: Both NL & CR
/*
