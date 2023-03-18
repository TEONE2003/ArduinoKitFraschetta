#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
 protected: ThermostatType TypeT; uint8_t PinRele,TemperatureThresholdS;
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRele,ReleType),
 VirtualCycleF(5,Seconds){this->TypeT=TypeT; this->PinRele=PinRele; TemperatureThresholdS=EEPROM.read(PinRele);}
 uint8_t TemperatureThreshold(){return TemperatureThresholdS;}
 void SetTemperatureThreshold(uint8_t TemperatureThreshold){
  EEPROM.update(PinRele,TemperatureThreshold);
  TemperatureThresholdS=TemperatureThreshold;
 }
 void ThermostatFunction(uint8_t CurrentTemperature){
  if(nTick()){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThresholdS){TurnOn();} else{TurnOff();}}
   else{if(CurrentTemperature>TemperatureThresholdS){TurnOn();} else {TurnOff();}}
  }
}
};
#endif
