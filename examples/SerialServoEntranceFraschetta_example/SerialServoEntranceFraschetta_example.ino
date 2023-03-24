#include "SerialServoEntranceFraschetta.h"
#include "BluetoothFraschetta.h"
SerialServoEntranceF S("S","SR",2,180,0,3,10,3,4,9600);
BluetoothF B(3,4,9600);
void setup(){S.MovementStatusCheck();}
void loop(){
B.ReceiveString();
S.FunctionSerialServoEntrance(B.ReadString());
if(S.InvalidCommand()){B.SendLn("INVALID COMMAND");}
}
/*THE INITIAL SPASMS DO NOT DEPEND ON THE CODE.
EVEN IF DISCONNECTING THE DATA CABLE OF THE SERVO MOTOR,
SPASMS STILL OCCUR.*/