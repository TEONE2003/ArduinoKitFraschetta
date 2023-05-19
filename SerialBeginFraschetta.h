#ifndef SerialBeginFraschetta_h
#define SerialBeginFraschetta_h
void SerialBeginF(long Baud=9600){static long B=0; if(Baud!=B){Serial.end(); Serial.begin(Baud);}}
#endif
