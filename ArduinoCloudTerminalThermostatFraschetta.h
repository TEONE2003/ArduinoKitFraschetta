#if defined(ARDUINO_UNOWIFIR4) || defined(ESP32)
#ifndef ArduinoCloudTerminalThermostatFraschetta_h
#define ArduinoCloudTerminalThermostatFraschetta_h
#include <BasicTerminalThermostatFraschetta.h>
class ArduinoCloudTerminalThermostatF: public BasicTerminalThermostatF{
#define ClassName BasicTerminalThermostatF
#include <ArduinoCloudTerminalConfig.h>
public: ArduinoCloudTerminalThermostatF(String *ReceivedString,bool *Readable,String Tag,uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):BasicTerminalThermostatF(ReceivedString,Readable,Tag,Pin,Type,TypeT){}
};
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif