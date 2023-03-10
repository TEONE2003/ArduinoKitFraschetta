#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include <BasicSerialFraschetta.h>
#include <SoftwareSerial.h>
class SERIALE:SoftwareSerial,public SERIALE_BASE{
protected:
 void INIZIALIZZA_SE_NON_INZIALIZZATO()override{if(!INIZIALIZZATO()){end(); begin(BAUD); I=1;}}
 boolean DATI_PRESENTI()override{return available()>0;}
 String STRINGA()override{return readString();}
 uint8_t BYTE()override{return read();}
 char CARATTERE()override{return read();}
public:
 SERIALE(const uint8_t &RX=2,const uint8_t &TX=3,const uint32_t &BAUD=9600):SoftwareSerial(RX,TX),SERIALE_BASE(BAUD){}
 template <typename T>
 void INVIA(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); print(t);}
 template <typename T>
 void INVIA_ANDANDO_A_CAPO(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); println(t);}
 void PONTE_SERIALE(){
  INIZIALIZZA_SE_NON_INZIALIZZATO();
  if(!PSERIALE){Serial.end(); Serial.begin(9600); PSERIALE=1;}
  if(Serial.available()){write(Serial.read());}
  if(available()){Serial.write(read());}
}
};
#endif
