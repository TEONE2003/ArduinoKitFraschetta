#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef ArduinoCloudTerminalDhtFraschetta_h
#define ArduinoCloudTerminalDhtFraschetta_h
#include <BasicTerminalDhtFraschetta.h>
class ArduinoCloudTerminalRelayF: public BasicTerminalDhtF{
#define ClassName BasicTerminalDhtF
#include <ArduinoCloudTerminalConfig.h>
public: ArduinoCloudTerminalRelayF(String *ReceivedString,bool *Readable, String Tag,uint8_t Pin,uint8_t Type):BasicTerminalDhtF(ReceivedString,Readable,Tag,Pin,Type){}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif