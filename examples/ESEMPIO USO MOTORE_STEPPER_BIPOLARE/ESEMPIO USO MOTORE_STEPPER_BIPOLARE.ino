#include "ArduinoKitFraschetta.h"
MOTORE_STEPPER_BIPOLARE M(2,3,4,5,200,5);
void setup(){

}
void loop(){
M.PASSO_A_SINISTRA();
}
