#ifndef PhotocellDuskToDawnFraschetta_h
#define PhotocellDuskToDawnFraschetta_h
#include "RelayFraschetta.h"
#include "PhotoresistorFraschetta.h"
class PhotocellDuskToDawnF:RelayF,PhotoresistorF{
protected: bool Bypass,PreviousRelayStatus,PreviousLightStatus;
public:
 PhotocellDuskToDawnF(uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
 uint8_t PinRele,DigitalType ReleType):PhotoresistorF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit),
 RelayF(PinRele,ReleType){Bypass=0; PreviousRelayStatus=0; PreviousLightStatus=0;}
 void PhotocellDuskToDawnFunction(){if(!Bypass){if(Check()){TurnOn();} else{TurnOff();}}}
 bool StatusLight(){return Check();}
 bool LightChanged(){if(Check()!=PreviousLightStatus){PreviousLightStatus=Check(); return 1;}return 0;}
 void BypassOn(){Bypass=1; TurnOn();}
 void BypassOff(){Bypass=0;}
 void InvertBypass(){if(Bypass){Bypass=0;} else{BypassOn();}}
 using RelayF::ReadDigitalStatus;
 bool RelayChanged(){if(ReadDigitalStatus()!=PreviousRelayStatus){PreviousRelayStatus=ReadDigitalStatus(); return 1;} return 0;}
 void Begin(){RelayF::Begin(); PhotoresistorF::Begin(); PreviousLightStatus=Check(); PreviousRelayStatus=ReadDigitalStatus();}
};
#endif

