#include "DhtFraschetta.h"
DhtF D(2,DHT11);
void setup(){Serial.begin(9600);}
void loop(){Serial.println(D.readTemperature()); delay(1000);}
