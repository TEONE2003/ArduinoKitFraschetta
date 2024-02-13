#include "SerialDhtFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(2,3,9600);
SerialDhtF D(B.GetStringAddress(),B.GetReadableAddress(),"D",2,DHT11,2,3,9600);
void setup(){}
void loop(){
 B.ReceiveString();
 D.SerialDhtFFunction();
 }
