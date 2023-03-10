#ifndef BasicSerialFraschetta_h
#define BasicSerialFraschetta_h
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
#endif
