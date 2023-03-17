#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include <RelayFraschetta.h>
#include <VirtualCycleFraschetta.h>
enum ThermostatType:boolean{Heating=1,Cooling=0};
class ThermostatF:RelayF,VirtualCycleF{
 protected:
  ThermostatType TypeT;
 public:
  uint8_t TemperatureThreshold=20;
 ThermostatF(uint8_t PinRele=0,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRele,ReleType),
 VirtualCycleF(10,Seconds){this->TypeT=TypeT;}
 void ThermostatFunction(uint8_t CurrentTemperature){
  if(nTick()){
   if(Heating){if(CurrentTemperature<TemperatureThreshold){TurnOn();} else{TurnOff();}}
   else{if(CurrentTemperature>TemperatureThreshold){TurnOn();} else {TurnOff();}}
  }
}
};
#endif