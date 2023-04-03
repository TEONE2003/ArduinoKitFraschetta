#include "DefaultSerialDhtFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(9600);
DefaultSerialDhtF D("D",2,DHT11,9600);
void setup(){}
void loop(){
 B.ReceiveString();
 D.SerialDhtFFunction(B.ReadString());
 if(D.InvalidCommand()){B.SendLn("INVALID COMMAND: ["+B.ReadString()+']');}
 }
