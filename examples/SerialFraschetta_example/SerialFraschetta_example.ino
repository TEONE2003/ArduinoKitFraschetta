#include "SerialFraschetta.h"
SerialF S(2,3);
void setup(){S.SetBaudRate(9600);}
void loop(){
S.ReceiveString();
if(S.ReadString()=="Hi"){S.SendLn("Hi");}
}
