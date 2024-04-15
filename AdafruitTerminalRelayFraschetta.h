#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#include "BasicTerminalRelayFraschetta.h"
#include "BasicAdafruitWifiFraschetta.h"



#else
#error This library requires an Arduino board with WiFi support.
#endif