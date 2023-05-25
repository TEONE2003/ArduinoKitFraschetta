#ifndef PhotocellDuskToDawnFraschetta_h
#define PhotocellDuskToDawnFraschetta_h
#include "RelayFraschetta.h"
#include "PhotoresistorFraschetta.h"
class PhotocellDuskToDawnF:RelayF,PhotoresistorF{
protected: bool active,bypass;
public:
 PhotocellDuskToDawnF(uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
 uint8_t PinRele,DigitalType ReleType):PhotoresistorF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit),
 RelayF(PinRele,ReleType){active=1; bypass=0;}
 void PhotocellDuskToDawnFunction(){if(active&&!bypass){if(NoLight()){RelayF::TurnOn();} else{RelayF::TurnOff();}}}
 void BypassOn(){bypass=1; RelayF::TurnOn();}
 void BypassOff(){bypass=0;}
 void InvertBypass(){if(bypass){bypass=0;} else{BypassOn();}}
 void On(){active=1;}
 void Off(){active=0; RelayF::TurnOff();}
 void InvertStatus(){if(active){Off();} else{active=1;}}
 bool Active(){return active;}
 bool Bypass(){return bypass;}
 using RelayF::StatusRelay;
 using RelayF::RelayChanged;
 using PhotoresistorF::Calibrate;
 using PhotoresistorF::Light;
 using PhotoresistorF::LightChanged;
 void Begin(){RelayF::Begin(); PhotoresistorF::Begin();}
};
#endif

