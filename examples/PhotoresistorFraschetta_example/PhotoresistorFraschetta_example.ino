#include "ArduinoKitFraschetta.h"

FOTORESISTORE F1(A0,800,200,1,SECONDI);

void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
digitalWrite(13,F1.CONTROLLO());
}
