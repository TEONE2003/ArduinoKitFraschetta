#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
class DhtF:DHT{
 protected: bool Initialized; void InitializesIfNotInitialized(){if(!Initialized){begin();}}
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){}
  float ReadTemperature(){InitializesIfNotInitialized(); return readTemperature();}
  float ReadHumidity(){InitializesIfNotInitialized(); return readHumidity();}
};
#endif
