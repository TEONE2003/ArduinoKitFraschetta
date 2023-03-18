#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
 protected: ThermostatType TypeT; uint8_t PinRele,TemperatureThreshold;
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRele,ReleType),
 VirtualCycleF(5,Seconds){this->TypeT=TypeT; this->PinRele=PinRele; TemperatureThreshold=EEPROM.read(PinRele);}
 void SetTemperatureThreshold(uint8_t TemperatureThreshold){
  EEPROM.update(PinRele,TemperatureThreshold);
  this->TemperatureThreshold=TemperatureThreshold;
 }
 void ThermostatFunction(uint8_t CurrentTemperature){
  if(nTick()){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThreshold){TurnOn();} else{TurnOff();}}
   else{if(CurrentTemperature>TemperatureThreshold){TurnOn();} else {TurnOff();}}
  }
}
};
#endif
