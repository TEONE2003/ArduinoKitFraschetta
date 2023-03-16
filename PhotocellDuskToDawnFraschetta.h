#ifndef PhotocellDuskToDawnFraschetta_h
#define PhotocellDuskToDawnFraschetta_h
#include <ReleFraschetta.h>
#include <PhotoresistorFraschetta.h>
class PhotocellDuskToDawnF:ReleF,Photoresistor{
public:
 PhotocellDuskToDawnF(uint8_t PinPhotoresistor,uint16_t TurnOnThreshold,uint16_t TurnOffThreshold,uint64_t Delay,TimeOfUnit Unit,
 uint8_t PinRele,Digitaltype ReleType):Photoresistor(PinPhotoresistor,TurnOnThreshold,TurnOffThreshold,Delay,Unit),
 ReleF(PinRele,ReleType){}
 void FunctionPhotocellDuskToDawn(){if(Control()){TurnOn();} else{TurnOff();}}
};
#endif
