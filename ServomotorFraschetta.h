#ifndef ServomotorFraschetta_h
#define ServomotorFraschetta_h
#include "Servo.h"
#include "EEPROM.h"
#include "MotorSwipingFraschetta.h"
class ServomotorF:Servo,MotorSwipingF{
 protected:
  uint8_t Pin;
  uint16_t Position()override{return EEPROM.read(Pin);}
  void Begin(){attach(Pin); write(uint8_t(Position())); delay(2);}
  void WritePosition(uint8_t Degrees){
   if(Degrees>180){Degrees=180;}
   write(Degrees);
   EEPROM.update(Pin,Degrees);
  }
  void IncreasePosition(uint8_t Degrees,uint16_t PeriodInMilliseconds){
    for(uint16_t P=Position();P<=Degrees;P++){
    WritePosition(P);
    delay(PeriodInMilliseconds);
    }
  }
  void DecreasePosition(uint8_t Degrees,uint16_t PeriodInMilliseconds){
    for(int16_t P=Position();P>=Degrees;P--){
    WritePosition(P);
    delay(PeriodInMilliseconds);
    }
  }
  void ForwardSwipe()override{SetPosition(ForwardPosition, MovementPeriodInMilliseconds);}
  void BackSwipe()override{SetPosition(BackPosition, MovementPeriodInMilliseconds);}
public:
 uint16_t MovementPeriodInMilliseconds;
 void SetPosition(uint16_t Degrees,uint16_t PeriodInMilliseconds){
  if(PeriodInMilliseconds>0){
   IncreasePosition(Degrees,PeriodInMilliseconds);
   DecreasePosition(Degrees,PeriodInMilliseconds);
  }
  else{WritePosition(Degrees);}
 }
 void Swiping(uint8_t ForwardPosition, uint8_t BackPosition,uint16_t IdleTime, UnitOfTime Unit){
  this->ForwardPosition = ForwardPosition;
  this->BackPosition = BackPosition;
  MotorSwipingF::Swiping(IdleTime,Unit);
 }
 ServomotorF(uint8_t Pin):Servo(),MotorSwipingF(){
  this->Pin = Pin;
  /*YOU CANNOT USE THE ‘attach’ FUNCTION BEFORE SETUP. I ASSUME THAT BEFORE SETUP THE MAIN FUNCTIONS
  OF THE DEVELOPMENT ENVIRONMENT ARE NOT INITIALIZED, SO IT WILL BE EXECUTED THE FIRST TIME
  YOU USE THE SERVOMOTOR.”*/
 }
};
#endif
