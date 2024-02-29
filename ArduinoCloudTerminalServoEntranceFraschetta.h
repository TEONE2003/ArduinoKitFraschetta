#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef ArduinoCloudTerminalServoEntranceFraschetta_h
#define ArduinoCloudTerminalServoEntranceFraschetta_h
#include <BasicTerminalServoEntranceFraschetta.h>
class ArduinoCloudTerminalRelayF: public BasicTerminalServoEntranceF{
#define ClassName BasicTerminalServoEntranceF
#include <ArduinoCloudTerminalConfig.h>
public: ArduinoCloudTerminalServoEntranceF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,uint16_t OpeningPosition,uint16_t ClosingPosition, uint16_t AddressMotionStatusPosition,uint16_t MovementDelayInMilliseconds):BasicTerminalServoEntranceF(ReceivedString,Readable,Tag,Pin,OpeningPosition,ClosingPosition,AddressMotionStatusPosition,MovementDelayInMilliseconds){}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif