#include "InputFraschetta.h"
InputF P(3);
void setup(){
Serial.begin(9600);
Serial.println(P.DigitalRead());
}
void loop(){}
