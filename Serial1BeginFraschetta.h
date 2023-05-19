#ifndef Serial1BeginFraschetta_h
#define Serial1BeginFraschetta_h
void Serial1BeginF(long Baud=9600){static long B=0; if(Baud!=B){Serial1.end(); Serial1.begin(Baud);}}
#endif
