#ifndef DhtFraschetta_h
#define DhtFraschetta_h
#include <DHT.h>
class DHT_F:DHT{
 protected:
  boolean INIZIALIZZATO;
  void INIZIALIZZA_SE_NON_INZIALIZZATO(){if(!INIZIALIZZATO){begin();}}
 public:
  DHT_F(uint8_t PIN,uint8_t TIPO):DHT(PIN,TIPO){}
  float LEGGI_TEMPERATURA(){
   INIZIALIZZA_SE_NON_INZIALIZZATO(); return readTemperature();}
  float LEGGI_UMIDITA(){
   INIZIALIZZA_SE_NON_INZIALIZZATO(); return readHumidity();}
};
#endif
