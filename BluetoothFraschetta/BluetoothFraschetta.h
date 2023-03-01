#ifndef BluetoothFraschetta_h
#define BluetoothFraschetta_h
#include <SerialFraschetta.h>
enum RUOLO{SLAVE,MASTER};
class AT{
protected:
 virtual void RICEVI_STRINGA()=0;
 virtual String LEGGI_STRINGA()=0;
 virtual void INVIA(String s)=0;
public:
 boolean MODALITA_AT_ABILITATA(){
 INVIA("AT");
 while(LEGGI_STRINGA()==""){RICEVI_STRINGA();}
 return LEGGI_STRINGA()=="OK";
 }
 void AT_RESETTA_IMPOSTAZIONI(){INVIA("AT+RESET");}
 void AT_IMPOSTA_NOME(String NOME){INVIA("AT+NAME"+NOME);}
 String AT_NOME(){
 INVIA("AT+NAME?");
 while(LEGGI_STRINGA()==""){RICEVI_STRINGA();}
 return LEGGI_STRINGA().substring(8,LEGGI_STRINGA().length()-8);
 }
 boolean AT_RUOLO(){
 INVIA("AT+ROLE?");
 while(LEGGI_STRINGA()==""){RICEVI_STRINGA();}
 return LEGGI_STRINGA().indexOf('1')>=0;
 }
 void AT_IMPOSTA_RUOLO(RUOLO R){
  if(R==MASTER){INVIA("AT+ROLE1");}
  else{INVIA("AT+ROLE0");}
  }
  AT_IMPOSTA_BAUD(uint8_t BAUD){INVIA("AT+BAUD"+String(BAUD));}
  AT_ASSOCIA(uint8_t INDIRIZZO_MAC){INVIA("AT+BIND"+String(INDIRIZZO_MAC));}
};

class BLUETOOTH:public SERIALE,public AT{
public:
 BLUETOOTH(uint8_t RX=2,uint8_t TX=3,uint32_t BAUD):SERIALE(RX,TX,BAUD){}
 void RICEVI_STRINGA()override{SERIALE::RICEVI_STRINGA();}
 String LEGGI_STRINGA()override{return SERIALE::LEGGI_STRINGA();}
 void INVIA(String s)override{SERIALE::INVIA(s);}
 template <typename T>
 void INVIA(T t){SERIALE::INVIA(t);}
};

class DEFAULT_BLUETOOTH:public DEFAULT_SERIAL,public AT{
public:
 DEFAULT_BLUETOOTH(uint32_t BAUD=9600):DEFAULT_SERIAL(BAUD){}
 void RICEVI_STRINGA()override{DEFAULT_SERIAL::RICEVI_STRINGA();}
 String LEGGI_STRINGA()override{return DEFAULT_SERIAL::LEGGI_STRINGA();}
 void INVIA(String s)override{DEFAULT_SERIAL::INVIA(s);}
 template <typename T>
 void INVIA(T t){DEFAULT_SERIAL::INVIA(t);}
};

#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DEFAULT1_BLUETOOTH:public DEFAULT_SERIAL1,public AT{
public:
 DEFAULT1_BLUETOOTH(uint32_t BAUD=9600):DEFAULT_SERIAL1(BAUD){}
 void RICEVI_STRINGA()override{DEFAULT_SERIAL1::RICEVI_STRINGA();}
 String LEGGI_STRINGA()override{return DEFAULT_SERIAL1::LEGGI_STRINGA();}
 void INVIA(String s)override{DEFAULT_SERIAL1::INVIA(s);}
};

class DEFAULT2_BLUETOOTH:public DEFAULT_SERIAL2,public AT{
public:
 DEFAULT2_BLUETOOTH(uint32_t BAUD=9600):DEFAULT_SERIAL2(BAUD){}
 void RICEVI_STRINGA()override{DEFAULT_SERIAL2::RICEVI_STRINGA();}
 String LEGGI_STRINGA()override{return DEFAULT_SERIAL2::LEGGI_STRINGA();}
 void INVIA(String s)override{DEFAULT_SERIAL2::INVIA(s);}
};

class DEFAULT3_BLUETOOTH:public DEFAULT_SERIAL3,public AT{
public:
 DEFAULT3_BLUETOOTH(uint32_t BAUD=9600):DEFAULT_SERIAL3(BAUD){}
 void RICEVI_STRINGA()override{DEFAULT_SERIAL3::RICEVI_STRINGA();}
 String LEGGI_STRINGA()override{return DEFAULT_SERIAL3::LEGGI_STRINGA();}
 void INVIA(String s)override{DEFAULT_SERIAL3::INVIA(s);}
};
#endif
#endif
