#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
protected: void Send(String S){*ClassName::ReceivedString=S;}
#else
#error This library requires an Arduino board with WiFi support.
#endif