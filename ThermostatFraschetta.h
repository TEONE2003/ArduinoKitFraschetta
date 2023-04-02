#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
protected: ThermostatType TypeT; uint8_t PinRele; byte TemperatureThresholdS; uint64_t nTick(){return VirtualCycleF::nTick();}
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRele,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRele,ReleType),
 VirtualCycleF(5,Seconds){this->TypeT=TypeT; this->PinRele=PinRele; TemperatureThresholdS=EEPROM.read(PinRele);}
 byte TemperatureThreshold(){return TemperatureThresholdS;}
 using RelayF::ReadDigitalStatus;
 using RelayF::Begin;
 void SetTemperatureThreshold(byte TemperatureThreshold){
  EEPROM.update(PinRele,TemperatureThreshold);
  TemperatureThresholdS=TemperatureThreshold;
 }
 void ThermostatFunction(byte CurrentTemperature){
  if(nTick()){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThresholdS){TurnOn();} else{TurnOff();}}
   else{if(CurrentTemperature>TemperatureThresholdS){TurnOn();} else {TurnOff();}}
  }
}
};
#endif
