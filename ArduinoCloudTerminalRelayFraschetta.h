#if defined(ESP8266) || defined(ESP32)
#ifndef ArduinoCloudTerminalRelayFraschetta_h
#define ArduinoCloudTerminalRelayFraschetta_h
#include <BasicTerminalRelayFraschetta.h>
class ArduinoCloudTerminalRelayF::BasicTerminalRelayF{
#include <ArduinoCloudTerminalConfigFraschetta.h>
public: ArduinoCloudTerminalRelayF(),BasicTerminalRelayF();
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif