#include <BluetoothFraschetta.h>
BluetoothF B(2,3,9600);
void setup(){pinMode(13,OUTPUT);}
void loop(){
B.ReceiveString();
if(B.ReadString()=="a"){digitalWrite(13,HIGH);}
else if(B.ReadString()=="b"){digitalWrite(13,LOW);}
else if(B.ReadString()!=""){B.SendLn("INVALID COMMAND");}
}