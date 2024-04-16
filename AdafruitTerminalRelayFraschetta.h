//#define ARDUINO_UNOWIFIR4
#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef AdafruitTerminalRelayFraschetta_h
#define AdafruitTerminalRelayFraschetta_h

#include "BasicTerminalRelayFraschetta.h"
#include "BasicAdafruitWifiFraschetta.h"

class AdafruitTerminalRelayF: public BasicTerminalRelayF{
private:
 BasicAdafruitWifiF& A;
public:
 AdafruitTerminalRelayF(String Tag,uint8_t Pin,DigitalType Type=NormalLogic,MemorizeStatus Save=DoNotSaveStatus):BasicTerminalRelayF(nullptr,nullptr,Tag,Pin,Type,Save){
  A = BasicAdafruitWifiF::GetInstance();
  ReceivedString = &A.ReceivedString;
  Readable = &A.Readable;
}
};


#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif