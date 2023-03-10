#ifndef TimerFraschetta_h
#define TimerFraschetta_h
#include <TimeFraschetta.h>
enum TIPO_TIMER{NON_BLOCCANTE,BLOCCANTE};
class TimerF:CronometroVirtualeF{
 protected:
  TEMPO PERIODO;
  TIPO_TIMER T_TIMER;
  boolean ABILITAT,T_INIZIALIZZATO;
 public:
  boolean INIZIALIZZATO(){return T_INIZIALIZZATO;}
  void ABILITA(){if(T_TIMER==NON_BLOCCANTE){avvia(); ABILITAT=1;}}
  boolean ABILITATO(){return ABILITAT;}
  void DISABILITA(){stoppa(); ABILITAT=0;}
  TEMPO tempoPassato_FINO_AD_ORA(){return tempoPassato();}
  void IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(uint64_t PERIODO,UNITA_DI_TEMPO UNITA){
  IMPOSTA_UNITA_DI_TEMPO(UNITA);
  this->PERIODO = TEMPO(PERIODO,UNITA);
  this->PERIODO.CONVERTI_IN(MICROSECONDI);
}
void IMPOSTA_TIPO_TIMER(TIPO_TIMER TIPO){T_TIMER=TIPO;}
boolean STOP(){
 switch(T_TIMER){
  case NON_BLOCCANTE: if(tempoPassato()>=PERIODO){DISABILITA(); return 1;}
    return 0;
  case BLOCCANTE: ASPETTA(PERIODO);
    return 1;
    }
}
TimerF(uint64_t PERIODO=0,UNITA_DI_TEMPO UNITA=SECONDI,TIPO_TIMER TIPO=NON_BLOCCANTE):CronometroVirtualeF(UNITA)
{IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(PERIODO,UNITA);  IMPOSTA_TIPO_TIMER(TIPO); T_INIZIALIZZATO=1;}
};
#endif
