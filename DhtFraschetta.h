#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
class DhtF:DHT{
 protected: bool I; void InitializesIfNotI(){if(!I){begin(); I=1;}}
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){I=0;}
  float ReadTemperature(){InitializesIfNotI(); return readTemperature();}
  float ReadHumidity(){InitializesIfNotI(); return readHumidity();}
};
#endif
