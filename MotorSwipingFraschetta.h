#ifndef MotorSwipingFraschetta_h
#define MotorSwipingFraschetta_h
#include "VirtualCycleFraschetta.h"
class MotorSwipingF{
 protected: VirtualCycleF C; uint16_t ForwardPosition,BackPosition; bool Ic;
 public:
  virtual uint16_t Position()=0;
  virtual void ForwardSwipe()=0;
  virtual void BackSwipe()=0;
  void Swiping(uint16_t IdleTime, UnitOfTime Unit){
   if(!Ic){C = VirtualCycleF(IdleTime,Unit); Ic=1;}
    for(uint64_t n=C.nTick();n>=1;n--){
     if(ForwardPosition>BackPosition){
      if(Position()<ForwardPosition){ForwardSwipe();}
      else if(Position()>BackPosition){BackSwipe();}
     }
     else{
      if(Position()>ForwardPosition){ForwardSwipe();}
      else if(Position()<BackPosition){BackSwipe();}
     }
     }
    }
    MotorSwipingF(uint16_t ForwardPosition=0,uint16_t BackPosition=0){
     this->ForwardPosition=ForwardPosition;
     this->BackPosition=BackPosition;
     Ic=0;
    }
};
#endif
