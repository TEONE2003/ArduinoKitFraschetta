#ifndef Serial2BeginFraschetta_h
#define Serial2BeginFraschetta_h
void Serial2BeginF(long Baud=9600){static long B=0; if(Baud!=B){Serial2.end(); Serial2.begin(Baud);}}
#endif
