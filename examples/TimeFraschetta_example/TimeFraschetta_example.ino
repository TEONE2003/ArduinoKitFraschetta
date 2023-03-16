#include "TimeFraschetta.h"
TimeF T(500,Milliseconds);
TimeF T1(500,Milliseconds);
void setup(){
Serial.begin(9600);
Serial.println(uint32_t(T.Value));
Serial.println(uint32_t(T.Microseconds()));
Serial.println(uint32_t(T.Nanoseconds()));
T.ConvertTo(Microseconds);
Serial.println(uint32_t(T.Value));
Serial.println(T1>=T);
}
void loop(){}
