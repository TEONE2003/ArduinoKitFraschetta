#include "SerialServoEntranceFraschetta.h"
#include "BluetoothFraschetta.h"
BluetoothF B(3,4,9600);
SerialServoEntranceF S(B.GetStringAddress(),B.GetReadableAddress(),"S",2,180,0,3,10,3,4,9600);
void setup(){S.MovementStatusCheck();}
void loop(){
B.ReceiveString();
S.FunctionSerialServoEntrance();
}
/*THE INITIAL SPASMS DO NOT DEPEND ON THE CODE.
EVEN IF DISCONNECTING THE DATA CABLE OF THE SERVO MOTOR,
SPASMS STILL OCCUR.*/