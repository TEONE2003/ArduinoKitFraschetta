#ifndef Serial3BeginFraschetta_h
#define Serial3BeginFraschetta_h
void Serial3BeginF(long Baud=9600){static long B=0; if(Baud!=B){Serial3.end(); Serial3.begin(Baud);}}
#endif
