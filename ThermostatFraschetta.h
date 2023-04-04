#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
protected: ThermostatType TypeT; uint8_t PinRele; byte TemperatureThresholdS; bool State;
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRele,ReleType),
  VirtualCycleF(5,Seconds){State=1; this->TypeT=TypeT; this->PinRele=PinRele; TemperatureThresholdS=EEPROM.read(PinRele);}
 byte TemperatureThreshold(){return TemperatureThresholdS;}
 using RelayF::ReadDigitalStatus;
 using RelayF::Begin;
 void SetTemperatureThreshold(byte TemperatureThreshold){
  EEPROM.update(PinRele,TemperatureThreshold);
  TemperatureThresholdS=TemperatureThreshold;
 }
 void TurnOn(){State=1; /*if(TemperatureThresholdS<0){SetTemperatureThreshold(-TemperatureThresholdS);*/}}
 void TurnOff(){State=0; /*if(TemperatureThresholdS>=0){SetTemperatureThreshold(-TemperatureThresholdS);*/}}
 void ThermostatFunction(byte CurrentTemperature){
  if(nTick() && State){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThresholdS){TurnOn();} else{RelayF::TurnOff();}}
   else{if(CurrentTemperature>TemperatureThresholdS){TurnOn();} else {RelayF::TurnOff();}}
  }
}
};
#endif
