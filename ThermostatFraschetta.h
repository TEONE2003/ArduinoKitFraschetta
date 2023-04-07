#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
protected: ThermostatType TypeT; uint8_t PinRelay; int8_t TemperatureThresholdS; bool State;
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRelay,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRelay,ReleType),
    VirtualCycleF(5,Seconds){State=0; this->TypeT=TypeT; this->PinRelay=PinRelay; TemperatureThresholdS=0;}
 uint8_t TemperatureThreshold(){return TemperatureThresholdS;}
 using RelayF::ReadDigitalStatus;
 void Begin(){
  RelayF::Begin();
  if(EEPROM.read(PinRelay)>49){EEPROM.update(PinRelay,int8_t(-20));}
  TemperatureThresholdS=EEPROM.read(PinRelay);
  if(TemperatureThresholdS<0){TemperatureThresholdS=-TemperatureThresholdS;}else{State=1;}
 }
 void SetTemperatureThreshold(uint8_t TemperatureThreshold){
  TemperatureThresholdS=TemperatureThreshold;
  if(!State){TemperatureThreshold=-TemperatureThreshold;}
  EEPROM.update(PinRelay,TemperatureThreshold);
 }
 void TurnOn(){State=1; SetTemperatureThreshold(TemperatureThresholdS);}
 void TurnOff(){State=0; SetTemperatureThreshold(TemperatureThresholdS);}
 void ThermostatFunction(uint8_t CurrentTemperature){
  if(nTick()>0 && State){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThresholdS){RelayF::TurnOn();} else{RelayF::TurnOff();}}
   else{if(CurrentTemperature>TemperatureThresholdS){RelayF::TurnOn();} else {RelayF::TurnOff();}}
  }
}
};
#endif
