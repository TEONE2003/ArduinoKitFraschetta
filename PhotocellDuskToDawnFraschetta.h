#ifndef PhotocellDuskToDawnFraschetta_h
#define PhotocellDuskToDawnFraschetta_h
#include "RelayFraschetta.h"
#include "PhotoresistorFraschetta.h"
class PhotocellDuskToDawnF:RelayF,PhotoresistorF{
protected: bool Bypass; CheckChangeF<bool>Change;
public:
 PhotocellDuskToDawnF(uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,UnitOfTime Unit,
 uint8_t PinRele,DigitalType ReleType):PhotoresistorF(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit),
 RelayF(PinRele,ReleType){Bypass=0; Change=CheckChangeF<bool>(false);}
 void PhotocellDuskToDawnFunction(){if(!Bypass){if(NoLight()){TurnOn();} else{TurnOff();}}}
 using PhotoresistorF::LightChanged;
 void BypassOn(){Bypass=1; TurnOn();}
 void BypassOff(){Bypass=0;}
 void InvertBypass(){if(Bypass){Bypass=0;} else{BypassOn();}}
 using RelayF::DigitalRead;
 using PhotoresistorF::Calibrate;
 using PhotoresistorF::Light;
 bool RelayChanged(){return Change.Changed(DigitalRead());}
 void Begin(){RelayF::Begin(); PhotoresistorF::Begin(); Change=CheckChangeF<bool>(DigitalRead());}
};
#endif

