#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include "DHT.h"
#include "CheckChangeFraschetta.h"
class DhtF:DHT{
 private: CheckChangeF<float>ChangeT,ChangeH;
 public:
  DhtF(uint8_t Pin,uint8_t Type):DHT(Pin,Type){ChangeT=CheckChangeF<float>(0); ChangeH=CheckChangeF<float>(0);}
  float ReadTemperature(){return readTemperature();}
  float ReadHumidity(){return readHumidity();}
  void Begin(){begin(); ChangeT=CheckChangeF<float>(ReadTemperature()); ChangeH=CheckChangeF<float>(ReadHumidity());}
  bool TemperatureChanged(){return ChangeT.Changed(ReadTemperature());}
  bool HumidityChanged(){return ChangeH.Changed(ReadHumidity());}
};
#endif
