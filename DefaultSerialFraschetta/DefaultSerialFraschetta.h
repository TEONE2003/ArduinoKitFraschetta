#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include <BasicSerialFraschetta.h>
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
