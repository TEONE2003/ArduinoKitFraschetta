#include "DefaultSerialDhtFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(9600);
DefaultSerialDhtF D(B.GetStringAddress(),B.GetReadableAddress(),"D",2,DHT11,9600);
void setup(){}
void loop(){
 B.ReceiveString();
 D.SerialDhtFFunction();
 }
