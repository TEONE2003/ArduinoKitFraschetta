#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include <DHT.h>
class DhtF:DHT{
 protected:
  boolean Initialized;
  void InitializesIfNotInitialized(){if(!Initialized){begin();}}
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){}
  float readTemperature(){
   InitializesIfNotInitialized(); return DHT::readTemperature();}
  float readHumidity(){
   InitializesIfNotInitialized(); return DHT::readHumidity();}
};
#endif
