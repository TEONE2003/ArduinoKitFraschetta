#include "DefaultSerialServoEntranceFraschetta.h"
#include "DefaultBluetoothFraschetta.h"
DefaultBluetoothF B(9600);
DefaultSerialServoEntranceF S(B.GetStringAddress(),B.GetReadableAddress(),"S",2,180,0,3,10,9600);
void setup(){S.MovementStatusCheck();}
void loop(){
B.ReceiveString();
S.FunctionSerialServoEntrance();
}
/*THE INITIAL SPASMS DO NOT DEPEND ON THE CODE.
EVEN IF DISCONNECTING THE DATA CABLE OF THE SERVO MOTOR,
SPASMS STILL OCCUR.*/