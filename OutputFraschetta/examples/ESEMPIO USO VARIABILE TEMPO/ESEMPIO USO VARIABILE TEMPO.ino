#include "ArduinoKitFraschetta.h"
TEMPO T(500,MILLISECONDI);
TEMPO T1(500,MILLISECONDI);
void setup(){
Serial.begin(9600);
Serial.println(uint32_t(T.VALORE));
Serial.println(uint32_t(T.MICROSECONDI()));
Serial.println(uint32_t(T.NANOSECONDI()));
T.CONVERTI_IN(MICROSECONDI);
Serial.println(uint32_t(T.VALORE));
Serial.println(T1>=T);
}
void loop(){}
