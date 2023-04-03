#include "DefaultSerialServoEntranceFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultSerialServoEntranceF S("S",2,180,0,3,10,9600);
DefaultBluetoothF B(9600);
void setup(){S.MovementStatusCheck();}
void loop(){
B.ReceiveString();
S.FunctionSerialServoEntrance(B.ReadString());
if(S.InvalidCommand()){B.SendLn("INVALID COMMAND: ["+B.ReadString()+']');}
}
/*THE INITIAL SPASMS DO NOT DEPEND ON THE CODE.
EVEN IF DISCONNECTING THE DATA CABLE OF THE SERVO MOTOR,
SPASMS STILL OCCUR.*/