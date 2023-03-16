#include "ArduinoKitFraschetta.h"
SERVO_INGRESSO S(2,180,0,3,10);
void setup(){S.CONTROLLO_STATO_MOVIMENTO();}
void loop(){
delay(3000);
/*bisogna mettere il delay qui perchè così qualsiasi
istruzione viene eseguita solo dopo i 3 secondi dopo il setup,
in questo caso verrebbe eseguito CHIUDI(); e APRI(); subito dopo,
quindi ci vuole il delay per separare il setup da loop*/
S.APRI();
delay(3000);
S.CHIUDI();
}
/*GLI SPASMI INIZIALI NON DIPENDONO DAl CODICE
SE ANCHE STACCANDO IL CAVO DATI DEL SERVOMOTORE
SI VERIFICA UNO SPASMO*/