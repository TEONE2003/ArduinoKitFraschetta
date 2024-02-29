#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef ArduinoCloudTerminalPhotocellDuskToDawnFraschetta_h
#define ArduinoCloudTerminalPhotocellDuskToDawnFraschetta_h
#include <BasicTerminalPhotocellDuskToDawnF.h>
class ArduinoCloudTerminalPhotocellDuskToDawnF: public BasicTerminalPhotocellDuskToDawnF{
#define ClassName BasicTerminalPhotocellDuskToDawnF
#include <ArduinoCloudTerminalConfig.h>
public: ArduinoCloudTerminalRelayF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
                      uint8_t PinRele,DigitalType ReleType):BasicTerminalPhotocellDuskToDawnF(ReceivedString,Readable,Tag,PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit,PinRele,ReleType){}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif