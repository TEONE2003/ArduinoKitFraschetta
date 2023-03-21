#include "SerialFraschetta.h"
SerialF S(2,3,9600);
void setup(){}
void loop(){
S.ReceiveString();
if(S.string()=="Hi"){S.SendLn("Hi");}
}
