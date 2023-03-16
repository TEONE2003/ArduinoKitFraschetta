#include "VirtualStopwatchFraschetta.h"
VirtualStopwatchF C(Milliseconds);
void setup(){
Serial.begin(9600);
C.Start();
delay(500);
Serial.println(uint32_t(C.ElapsedTime().Value));
C.Stop();
}
void loop(){}
