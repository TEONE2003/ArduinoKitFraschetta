#include <DefaultBluetoothFraschetta.h>
DefaultBluetoothF B(9600);
void setup(){pinMode(13,OUTPUT);}
void loop(){
B.ReceiveString();
if(B.Readable()){
if(B.ReadString()=="a"){digitalWrite(13,HIGH);}
else if(B.ReadString()=="b"){digitalWrite(13,LOW);}
else if(B.ReadString()!=""){B.SendLn("INVALID COMMAND: ["+B.ReadString()+"]");}
}
}
