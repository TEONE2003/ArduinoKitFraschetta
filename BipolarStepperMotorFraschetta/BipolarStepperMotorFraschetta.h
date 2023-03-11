#ifndef BipolarStepperMotorFraschetta_h
#define BipolarStepperMotorFraschetta_h
#include <BasicStepperMotorFraschetta.h>
class MOTORE_STEPPER_BIPOLARE:public MOTORE_STEPPER_BASE{
protected:
 uint8_t PIN_A,PIN_B,PIN_C,PIN_D;
 void STOP(){
  digitalWrite(PIN_A,0); digitalWrite(PIN_B,0);
  digitalWrite(PIN_C,0); digitalWrite(PIN_D,0);
 }
 void STEP_DESTRA(uint8_t N_STEP){
  digitalWrite(PIN_A,N_STEP==1);
  digitalWrite(PIN_B,N_STEP==2);
  digitalWrite(PIN_C,N_STEP==3);
  digitalWrite(PIN_D,N_STEP==4);
  delay(4);
 }
 void STEP_SINISTRA(uint8_t N_STEP){
  digitalWrite(PIN_A,N_STEP==1);
  digitalWrite(PIN_B,N_STEP==4);
  digitalWrite(PIN_C,N_STEP==3);
  digitalWrite(PIN_D,N_STEP==2);
  delay(4);
 }
public:
 void PASSO_A_DESTRA()override{
  STEP_DESTRA(1);
  STEP_DESTRA(2);
  STEP_DESTRA(3);
  STEP_DESTRA(4);
  MEMORIZZA_PASSI(POSIZIONE()+1);
  STOP();
 }
 void PASSO_A_SINISTRA()override{
  STEP_SINISTRA(1);
  STEP_SINISTRA(2);
  STEP_SINISTRA(3);
  STEP_SINISTRA(4);
  MEMORIZZA_PASSI(POSIZIONE()-1);
  delay(PERIODO_SPOSTAMENTO_IN_MILLISECONDI);
  STOP();
 }
  MOTORE_STEPPER_BIPOLARE(uint8_t PIN_A,uint8_t PIN_B,uint8_t PIN_C,uint8_t PIN_D,uint16_t PASSI_MASSIMI,uint16_t PERIODO_SPOSTAMENTO_IN_MILLISECONDI):
  MOTORE_STEPPER_BASE(PASSI_MASSIMI,PERIODO_SPOSTAMENTO_IN_MILLISECONDI,PIN_A,PIN_B){
   this->PIN_A=PIN_A; this->PIN_B=PIN_B; this->PIN_C=PIN_C; this->PIN_D=PIN_D;
   pinMode(PIN_A,OUTPUT); pinMode(PIN_B,OUTPUT); pinMode(PIN_C,OUTPUT); pinMode(PIN_D,OUTPUT);
  }
};
#endif
