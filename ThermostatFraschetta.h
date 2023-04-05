#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include "RelayFraschetta.h"
#include "VirtualCycleFraschetta.h"
enum ThermostatType{Heating,Cooling};
class ThermostatF:RelayF,VirtualCycleF{
protected: ThermostatType TypeT; uint8_t PinRelay; byte TemperatureThresholdS; bool State;
 public:
 ThermostatF(){}
 ThermostatF(uint8_t PinRelay,DigitalType ReleType=NormalLogic,ThermostatType TypeT=Heating):RelayF(PinRelay,ReleType),
    VirtualCycleF(5,Seconds){State=1; this->TypeT=TypeT; this->PinRelay=PinRelay; TemperatureThresholdS=0;}
 byte TemperatureThreshold(){return TemperatureThresholdS;}
 using RelayF::ReadDigitalStatus;
 void Begin(){
  RelayF::Begin();
  if(EEPROM.read(PinRelay)>49){EEPROM.update(PinRelay,20);}
  TemperatureThresholdS=EEPROM.read(PinRelay);
 }
 void SetTemperatureThreshold(byte TemperatureThreshold){
  EEPROM.update(PinRelay,TemperatureThreshold);
  TemperatureThresholdS=TemperatureThreshold;
 }
 void TurnOn(){State=1; /*if(TemperatureThresholdS<0){SetTemperatureThreshold(-TemperatureThresholdS);}*/}
 void TurnOff(){State=0; /*if(TemperatureThresholdS>=0){SetTemperatureThreshold(-TemperatureThresholdS);}*/}
 void ThermostatFunction(byte CurrentTemperature){
  if(nTick() && State){
   if(TypeT==Heating){if(CurrentTemperature<TemperatureThresholdS){TurnOn();} else{RelayF::TurnOff();}}
   else{if(CurrentTemperature>TemperatureThresholdS){TurnOn();} else {RelayF::TurnOff();}}
  }
}
};
#endif
