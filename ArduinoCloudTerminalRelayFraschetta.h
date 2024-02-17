#define ESP32
//#define ESP8266
#if defined(ESP8266) || defined(ESP32)
#ifndef ArduinoCloudTerminalRelayFraschetta_h
#define ArduinoCloudTerminalRelayFraschetta_h
#include <BasicTerminalRelayFraschetta.h>
class ArduinoCloudTerminalRelayFraschetta::BasicTerminalRelayF{
protected: void Send(String S){*BasicTerminalRelayF::ReceivedString=S;}
public: ArduinoCloudTerminalRelayFraschetta(),BasicTerminalRelayF();
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif