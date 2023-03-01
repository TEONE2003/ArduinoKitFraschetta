#ifndef SerialFraschetta_h
#define SerialFraschetta_h
#include "SoftwareSerial.h"
class SERIALE_BASE{
protected:
 String S;
 uint8_t B;
 char C;
 boolean I,PSERIALE;
 uint16_t BAUD;
 uint8_t TX;
 uint8_t RX;
 virtual void INIZIALIZZA_SE_NON_INZIALIZZATO()=0;
 virtual boolean DATI_PRESENTI()=0;
 virtual String STRINGA()=0;
 virtual uint8_t BYTE()=0;
 virtual char CARATTERE()=0;
public:
 boolean INIZIALIZZATO(){return I;}
 void RICEVI_STRINGA(){
  INIZIALIZZA_SE_NON_INZIALIZZATO();
  if(DATI_PRESENTI()){S=STRINGA();}
  else{S="";}
 }
 void RICEVI_BYTE(){
  INIZIALIZZA_SE_NON_INZIALIZZATO();
  if(DATI_PRESENTI()){B=BYTE();}
  else{B=0;}
 }
 void RICEVI_CARATTERE(){
  INIZIALIZZA_SE_NON_INZIALIZZATO();
  if(DATI_PRESENTI()){C=CARATTERE();}
  else{C=0;}
}
 String LEGGI_STRINGA(){return S;}
 uint8_t LEGGI_BYTE(){return B;}
 char LEGGI_CHAR(){return C;}
 SERIALE_BASE(const uint16_t &BAUD=9600){this->BAUD=BAUD;}
};

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

class DEFAULT_SERIAL:public SERIALE_BASE{
protected:
 void INIZIALIZZA_SE_NON_INZIALIZZATO()override{if(!INIZIALIZZATO()){Serial.end(); Serial.begin(BAUD); I=1;}}
 boolean DATI_PRESENTI()override{return Serial.available()>0;}
 String STRINGA()override{return Serial.readString();}
 uint8_t BYTE()override{return Serial.read();}
 char CARATTERE()override{return Serial.read();}
public:
 DEFAULT_SERIAL(const uint32_t &BAUD=9600):SERIALE_BASE(BAUD){}
 template <typename T>
 void INVIA(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial.print(t);}
 template <typename T>
 void INVIA_ANDANDO_A_CAPO(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial.println(t);}
};

#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DEFAULT_SERIAL1:public SERIALE_BASE{
protected:
 void INIZIALIZZA_SE_NON_INZIALIZZATO()override{if(!INIZIALIZZATO()){Serial1.end(); Serial1.begin(BAUD); I=1;}}
 boolean DATI_PRESENTI()override{return Serial1.available()>0;}
 String STRINGA()override{return Serial1.readString();}
 uint8_t BYTE()override{return Serial1.read();}
 char CARATTERE()override{return Serial1.read();}
public:
 DEFAULT_SERIAL1(const uint32_t &BAUD=9600):SERIALE_BASE(BAUD){}
 template <typename T>
 void INVIA(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial1.print(t);}
 template <typename T>
 void INVIA_ANDANDO_A_CAPO(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial1.println(t);}
};

class DEFAULT_SERIAL2:public SERIALE_BASE{
protected:
 void INIZIALIZZA_SE_NON_INZIALIZZATO()override{if(!INIZIALIZZATO()){Serial2.end(); Serial2.begin(BAUD); I=1;}}
 boolean DATI_PRESENTI()override{return Serial2.available()>0;}
 String STRINGA()override{return Serial2.readString();}
 uint8_t BYTE()override{return Serial2.read();}
 char CARATTERE()override{return Serial2.read();}
public:
 DEFAULT_SERIAL2(const uint32_t &BAUD=9600):SERIALE_BASE(BAUD){}
 template <typename T>
 void INVIA(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial2.print(t);}
 template <typename T>
 void INVIA_ANDANDO_A_CAPO(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial2.println(t);}
};

class DEFAULT_SERIAL3:public SERIALE_BASE{
protected:
 void INIZIALIZZA_SE_NON_INZIALIZZATO()override{if(!INIZIALIZZATO()){Serial3.end(); Serial3.begin(BAUD); I=1;}}
 boolean DATI_PRESENTI()override{return Serial3.available()>0;}
 String STRINGA()override{return Serial3.readString();}
 uint8_t BYTE()override{return Serial3.read();}
 char CARATTERE()override{return Serial3.read();}
public:
 DEFAULT_SERIAL3(const uint32_t &BAUD=9600):SERIALE_BASE(BAUD){}
 template <typename T>
 void INVIA(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial3.print(t);}
 template <typename T>
 void INVIA_ANDANDO_A_CAPO(T t){INIZIALIZZA_SE_NON_INZIALIZZATO(); Serial3.println(t);}
};
#endif
#endif
