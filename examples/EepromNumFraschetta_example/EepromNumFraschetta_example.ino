#include "EepromNumFraschetta.h"
EepromNumF::EepromUint32T N(200,0,50,100); //Your Arduino Uno is not working with writing to 64-bit numbers using bitWrite
void setup() {
Serial.begin(9600);
N.Value(16868);
Serial.println(N.Value());
}
void loop() {}
