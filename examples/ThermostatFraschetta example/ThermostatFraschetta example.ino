#include "ArduinoKitFraschetta.h"

TERMOSTATO T(13,NORMALE,RISCALDAMENTO);

void setup() {}

void loop() {
T.FUNZIONE_TERMOSTATO(24);
}
