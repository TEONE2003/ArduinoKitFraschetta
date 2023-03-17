#ifndef TwoStageThermostatFraschetta_h
#define TwoStageThermostatFraschetta_h
#include <ThermostatFraschetta.h>
class TwoStageThermostatF{
 protected:
    ThermostatF ThermostatHeating,ThermostatCooling;
 public:
  TwoStageThermostatF(uint8_t HeatingPin=0,DigitalType HeatingRelayType=NormalLogic,uint8_t CoolingPin=0,DigitalType CoolingRelayType=NormalLogic){
   ThermostatHeating = ThermostatF(HeatingPin,HeatingRelayType,Heating);
   ThermostatCooling = ThermostatF(CoolingPin,CoolingRelayType,Cooling);
  }
  TwoStageThermostatF(uint8_t HeatingPin,uint8_t CoolingPin,DigitalType RelayType):
  TwoStageThermostatF(HeatingPin,RelayType,CoolingPin,RelayType){}
  void TwoStageThermostatFunction(uint8_t CurrentTemperature){
   ThermostatHeating.ThermostatFunction(CurrentTemperature);
   ThermostatCooling.ThermostatFunction(CurrentTemperature);
  }
  void SetTemperatureThreshold(uint8_t Temperature){
   ThermostatHeating.TemperatureThreshold = Temperature;
   ThermostatHeating.TemperatureThreshold = Temperature;
  }
  uint8_t TemperatureThreshold(){return ThermostatHeating.TemperatureThreshold;}
};
#endif
