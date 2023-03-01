#include "ArduinoKitFraschetta.h"
BLUETOOTH B(2,3,9600);
LED L(13);
void setup(){}
void loop(){
B.RICEVI_STRINGA();
if(B.LEGGI_STRINGA()=="a"){L.ACCENDI();}
else if(B.LEGGI_STRINGA()=="b"){L.SPEGNI();}
else if(B.LEGGI_STRINGA()!=""){B.INVIA_ANDANDO_A_CAPO("COMANDO NON VALIDO");}
}
