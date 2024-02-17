#define ESP32
//#define ESP8266
#if defined(ESP8266) || defined(ESP32)
#ifndef ArduinoCloudTerminalConfigFraschetta_h
#define ArduinoCloudTerminalConfigFraschetta_h
template <typename T>
class ArduinoCloudTerminalConfigFraschetta{
protected: void Send(String S){ T::*ReceivedString=S;}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif