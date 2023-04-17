#ifndef PhotocellDuskToDawnFraschetta_h
#define PhotocellDuskToDawnFraschetta_h
#include "RelayFraschetta.h"
#include "PhotoresistorFraschetta.h"
class PhotocellDuskToDawnF:RelayF,PhotoresistorF{
private: bool Bypass;
public:
 PhotocellDuskToDawnF(uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
 uint8_t PinRele,DigitalType ReleType):PhotoresistorF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit),
 RelayF(PinRele,ReleType){Bypass=0;}
 void PhotocellDuskToDawnFunction(){if(!Bypass){if(Check()){TurnOn();} else{TurnOff();}}}
 void BypassOn(){Bypass=1; TurnOn();}
 void BypassOff(){Bypass=0;}
 using RelayF::ReadDigitalStatus;
 void Begin(){RelayF::Begin(); PhotoresistorF::Begin();}
};
#endif
