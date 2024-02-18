#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef ArduinoCloudTerminalRelayFraschetta_h
#define ArduinoCloudTerminalRelayFraschetta_h
#include <BasicTerminalRelayFraschetta.h>
class ArduinoCloudTerminalRelayF:: public BasicTerminalRelayF{
#include <ArduinoCloudTerminalConfigFraschetta.h>
public: ArduinoCloudTerminalRelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus),BasicTerminalRelayF(ReceivedString,Readable,Tag,Pin,Type,MemorizeStatus){}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif