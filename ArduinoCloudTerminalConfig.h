#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
protected: void Send(String S){*ClassName::ReceivedString=char(125)+ S + char(125);}
#else
#error This library requires an Arduino board with WiFi support.
#endif