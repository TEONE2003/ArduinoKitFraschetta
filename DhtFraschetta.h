#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include <DHT.h>
class Dht_F:DHT{
 protected:
  boolean Initialized;
  void InitializesIfNotInitialized(){if(!Initialized){begin();}}
 public:
  Dht_F(uint8_t Pin,uint8_t Type):DHT(Pin,Type){}
  float ReadTemperature(){
   InitializesIfNotInitialized(); return readTemperature();}
  float ReadHumidity(){
   InitializesIfNotInitialized(); return readHumidity();}
};
#endif
