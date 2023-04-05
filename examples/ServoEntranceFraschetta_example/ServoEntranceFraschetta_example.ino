#include "ServoEntranceFraschetta.h"
ServoEntranceF S(2,180,0,3,10);
void setup(){S.Begin();}
void loop(){
delay(3000);
/*We need to put the delay here so that any instruction is executed
only after 3 seconds after the setup.
In this case, Close(); and Open(); would be executed immediately
after, so we need the delay to separate the setup from the loop.*/
S.Open();
delay(3000);
S.Close();
}
/*THE INITIAL SPASMS DO NOT DEPEND ON THE CODE.
EVEN IF DISCONNECTING THE DATA CABLE OF THE SERVO MOTOR,
SPASMS STILL OCCUR.*/