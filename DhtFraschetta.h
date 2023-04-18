#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
class DhtF:DHT{
 private: float PreviousT,PreviousH;
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){PreviousT=0; PreviousH=0;}
  void Begin(){begin(); PreviousT=readTemperature(); PreviousH=readHumidity();}
  float ReadTemperature(){return readTemperature();}
  float ReadHumidity(){return readHumidity();}
  bool TemperatureChanged(){if(PreviousT!=readTemperature()){PreviousT=readTemperature(); return 1;}return 0;}
  bool HumidityChanged(){if(PreviousH!=readHumidity()){PreviousH=readHumidity(); return 1;}return 0;}
};
#endif
