#include "SerialDhtFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialDhtF D("D",2,DHT11,2,3,9600);
void setup(){}
void loop(){
 B.ReceiveString();
 D.SerialDhtFFunction(B.ReadString());
 if(D.InvalidCommand()){B.SendLn("INVALID COMMAND");}
 }
