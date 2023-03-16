#ifndef MotorSwipingFraschetta_h
#define MotorSwipingFraschetta_h
#include <VirtualCycleFraschetta.h>
class MotorSwipingF{
 public:
  VirtualCycleF C;
  uint16_t ForwardPosition,BackPosition;
  virtual uint16_t Position()=0;
  virtual void ForwardSwipe()=0;
  virtual void BackSwipe()=0;
  void Swiping(uint16_t IdleTime, TimeOfUnit Unit){
   if(!C.Initialized()){C = VirtualCycleF(IdleTime,Unit);}
    if(C.Tick()){
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
    }
};
#endif
