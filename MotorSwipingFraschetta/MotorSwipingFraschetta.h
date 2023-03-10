#ifndef MotorSwipingFraschetta_h
#define MotorSwipingFraschetta_h
#include <VirtualCycleFraschetta.h>
class MOTORE_SWIPING{
 public:
  CicloVirtualeF C;
  uint16_t POSIZIONE_AVANTI,POSIZIONE_INDIETRO;
  virtual uint16_t POSIZIONE()=0;
  virtual void SWIPE_AVANTI()=0;
  virtual void SWIPE_INDIETRO()=0;
  void SWIPING(uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
   if(!C.INIZIALIZZATO()){C = CicloVirtualeF(TEMPO_DA_FERMO,UNITA);}
    if(C.TICK()){
     if(POSIZIONE_AVANTI>POSIZIONE_INDIETRO){
      if(POSIZIONE()<POSIZIONE_AVANTI){SWIPE_AVANTI();}
      else if(POSIZIONE()>POSIZIONE_INDIETRO){SWIPE_INDIETRO();}
     }
     else{
      if(POSIZIONE()>POSIZIONE_AVANTI){SWIPE_AVANTI();}
      else if(POSIZIONE()<POSIZIONE_INDIETRO){SWIPE_INDIETRO();}
     }
     }
    }
    MOTORE_SWIPING(){}
};
#endif
