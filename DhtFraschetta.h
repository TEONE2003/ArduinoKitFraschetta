#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
class DhtF:DHT{
 private: bool I; float PreviousT,PreviousH;
 void InitializesIfNotI(){if(!I){begin(); I=1; PreviousT=readTemperature(); PreviousH=readHumidity();}}
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){I=0; PreviousT=0; PreviousH=0;}
  float ReadTemperature(){InitializesIfNotI(); return readTemperature();}
  float ReadHumidity(){InitializesIfNotI(); return readHumidity();}
  bool TemperatureChanged(){InitializesIfNotI(); if(PreviousT!=readTemperature()){PreviousT=readTemperature(); return 1;}return 0;}
  bool HumidityChanged(){InitializesIfNotI(); if(PreviousH!=readHumidity()){PreviousH=readHumidity(); return 1;}return 0;}
};
#endif
