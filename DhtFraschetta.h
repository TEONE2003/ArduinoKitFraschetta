#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
class DhtF:DHT{
 private: bool I; float PreviousT,PreviousH; void InitializesIfNotI(){if(!I){begin(); I=1;}}
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){I=0; PreviousT=0; PreviousH=0;}
  float ReadTemperature(){InitializesIfNotI(); PreviousT=readTemperature(); return PreviousT;}
  float ReadHumidity(){InitializesIfNotI(); PreviousH=readHumidity(); return PreviousH;}
  bool TemperatureChanged(){return PreviousT!=readTemperature();}
  bool HumidityChanged(){return PreviousH!=readHumidity();}
};
#endif
