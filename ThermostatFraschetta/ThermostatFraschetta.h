#ifndef ThermostatFraschetta_h
#define ThermostatFraschetta_h
#include <ReleFraschetta.h>
#include <VirtualCycleFraschetta.h>
enum ThermostatType:boolean{RISCALDAMENTO=1,RAFFREDDAMENTO=0};
class Thermostat:Rele,CicloVirtualeF{
 protected:
  ThermostatType TypeT;
 public:
  uint8_t SOGLIA_TEMPERATURA=20;
 Thermostat():Rele(){}
 Thermostat(uint8_t PinRele,TIPO_DIGITALE TIPORele,ThermostatType TypeT):Rele(PinRele,TIPORele),
 CicloVirtualeF(10,SECONDI){this->TypeT=TypeT;}
 void FUNZIONE_Thermostat(uint8_t TEMPERATURA_ATTUALE){
  if(TICK()){
   if(RISCALDAMENTO){if(TEMPERATURA_ATTUALE<SOGLIA_TEMPERATURA){ACCENDI();} else{SPEGNI();}}
   else{if(TEMPERATURA_ATTUALE>SOGLIA_TEMPERATURA){ACCENDI();} else {SPEGNI();}}
  }
}
};
#endif
