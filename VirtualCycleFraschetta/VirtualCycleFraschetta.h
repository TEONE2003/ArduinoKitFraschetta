#ifndef VirtualCycleFraschetta_h
#define VirtualCycleFraschetta_h
#include <VirtualStopwatchFraschetta.h>
class CicloVirtualeF:CronometroVirtualeF{
protected: TEMPO Periodo; uint64_t Div;
public:
    CicloVirtualeF(uint64_t Periodo=0,UNITA_DI_TEMPO Unita=MILLISECONDI):CronometroVirtualeF(UNITA){this->Periodo=TEMPO(Periodo,Unita);}
 TEMPO tempoPassato(){return CronometroVirtualeF::tempoPassato();}
 uint64_t nTick(){
  avvia();
  Div=tempoPassato()/Periodo;
  if(Div>=1){stoppa();}
  return Div;
 }
};
#endif
