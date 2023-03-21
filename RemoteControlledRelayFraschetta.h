#ifndef RemoteControlledRelayFraschetta_h
#define RemoteControlledRelayFraschetta_h
#include <RelayFraschetta.h>
enum SerialType{Software,Default,Default1,Default2,Default3}
class RemoteControlledRelayF:public RelayF{
protected: SerialType serialType;
public:
 String Tag;
 BluetoothRelayF(){}
    BluetoothRelayF(uint8_t Pin,String Tag,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus,SerialType serialType):RelayF(Pin,Type,Save){this->Tag=Tag; this->serialType=serialType;}
  
};
#endif
