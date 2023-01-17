#ifndef ArduinoKitFraschetta_h
#define ArduinoKitFraschetta_h
#include "EEPROM.h"
#include "Servo.h"
#include "Stepper.h"
#include "DHT.h"
#include "SoftwareSerial.h"
#include "stdint.h"

class SERIALE:SoftwareSerial{
private:
String S;
boolean I;
uint16_t BAUD;
uint8_t TX;
uint8_t RX;
public:
boolean INIZIALIZZATO(){return I;}
private:
void INIZIALIZZA_SE_NON_INZIALIZZATO(){if(!INIZIALIZZATO()){pinMode(RX,INPUT); pinMode(TX,OUTPUT); end(); begin(BAUD); I=1;}}
public:
SERIALE(uint8_t RX,uint8_t TX,uint32_t BAUD):SoftwareSerial(RX,TX){this->BAUD=BAUD; this->TX=TX; this->RX=RX;}
void RICEVI_STRINGA(){
INIZIALIZZA_SE_NON_INZIALIZZATO();
if(available()){S = readString();}
else{S="";}
}
String LEGGI_STRINGA(){return S;}
void INVIA_STRINGA(String S){print(S);}
void INVIA_STRINGA_ANDANDO_A_CAPO(String S){println(S);}
};

class BLUETOOTH:public SERIALE{
public:
BLUETOOTH(uint8_t RX,uint8_t TX,uint32_t BAUD):SERIALE(RX,TX,BAUD){}
};

enum UNITA_DI_TEMPO{NANOSECONDI,MICROSECONDI,MILLISECONDI,SECONDI,MINUTI,ORE,GIORNI,SETTIMANE,MESI_COMMERCIALI,ANNI,ANNI_COMMERCIALI};
struct TEMPO{
protected:
 uint64_t REST;
 uint64_t DIVISORE;
public:
UNITA_DI_TEMPO UNITA=UNITA_DI_TEMPO::MICROSECONDI;
uint64_t VALORE;
    uint64_t NANOSECONDI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                REST=0;
                return VALORE*1000;
            case UNITA_DI_TEMPO::MILLISECONDI:
                REST=0;
                return VALORE*1000000;
            case UNITA_DI_TEMPO::SECONDI:
                REST=0;
                return VALORE*1000000000;
            case UNITA_DI_TEMPO::MINUTI:
                REST=0;
                return VALORE*60000000000;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE*3600000000000;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*8640000000000;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*60480000000000;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*259200000000000;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*3153600000000000;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*3110400000000000;
        }
    }
    uint64_t MICROSECONDI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=1000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                REST=0;
                return VALORE*1000;
            case UNITA_DI_TEMPO::SECONDI:
                REST=0;
                return VALORE*1000000;
            case UNITA_DI_TEMPO::MINUTI:
                REST=0;
                return VALORE*60000000;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE*3600000000;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*86400000000;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*604800000000;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*2592000000000;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*31536000000000;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*31104000000000;
        }
    }
    uint64_t MILLISECONDI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=1000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=1000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::SECONDI:
                REST=0;
                return VALORE*1000;
            case UNITA_DI_TEMPO::MINUTI:
                REST=0;
                return VALORE*60000;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE*3600000;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*86400000;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*604800000;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*2592000000;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*31536000000;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*31104000000;
        }
    }
    uint64_t SECONDI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=1000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=1000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=1000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::MINUTI:
                REST=0;
                return VALORE*60;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE*3600;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*86400;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*604800;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*2592000;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*31536000;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*31104000;
        }
    }
    uint64_t MINUTI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=60000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=60000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=60000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=60;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE*60;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*1440;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*10080;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*43200;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*525600;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*518400;
        }
    }
    uint64_t ORE(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=3600000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=3600000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=3600000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=3600;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=60;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE*24;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*168;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*720;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*8760;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*8640;
        }
    }
    uint64_t GIORNI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=86400000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=86400000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=86400000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=86400;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=1440;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                DIVISORE=24;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::GIORNI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE*7;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*30;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*365;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*360;
        }
    }
    uint64_t SETTIMANE(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=60480000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=604800000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=604800000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=604800;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=10080;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                DIVISORE=168;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::GIORNI:
                DIVISORE=7;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SETTIMANE:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE*210;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*2555;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*2520;
        }
    }
    uint64_t MESI_COMMERCIALI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=2592000000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=42336000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=2592000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=2592000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=43200;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                DIVISORE=720;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::GIORNI:
                DIVISORE=30;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SETTIMANE:
                DIVISORE=4;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE*4380;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE*4320;
        }
    }
    uint64_t ANNI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=3153600000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=3153600000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=31536000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=31536000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=525600;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                DIVISORE=8760;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::GIORNI:
                DIVISORE=365;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SETTIMANE:
                DIVISORE=48;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                DIVISORE=12;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE;
        }
    }
    uint64_t ANNI_COMMERCIALI(){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                DIVISORE=31104000000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MICROSECONDI:
                DIVISORE=31104000000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MILLISECONDI:
                DIVISORE=31104000000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SECONDI:
                DIVISORE=518400000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MINUTI:
                DIVISORE=31104000;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ORE:
                DIVISORE=8640;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::GIORNI:
                DIVISORE=360;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::SETTIMANE:
                DIVISORE=48;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                DIVISORE=12;
                REST=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case UNITA_DI_TEMPO::ANNI:
                REST=0;
                return VALORE;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                REST=0;
                return VALORE;
        }
    }
    void CONVERTI_IN(UNITA_DI_TEMPO UNITA){
        switch(UNITA){
            case UNITA_DI_TEMPO::NANOSECONDI:
                VALORE = NANOSECONDI();
                break;
            case UNITA_DI_TEMPO::MICROSECONDI:
                VALORE = MICROSECONDI();
                break;
            case UNITA_DI_TEMPO::MILLISECONDI:
                VALORE = MILLISECONDI();
                break;
            case UNITA_DI_TEMPO::SECONDI:
                VALORE = SECONDI();
                break;
            case UNITA_DI_TEMPO::MINUTI:
                VALORE = MINUTI();
                break;
            case UNITA_DI_TEMPO::ORE:
                VALORE = ORE();
                break;
            case UNITA_DI_TEMPO::GIORNI:
                VALORE = GIORNI();
                break;
            case UNITA_DI_TEMPO::SETTIMANE:
                VALORE = SETTIMANE();
                break;
            case UNITA_DI_TEMPO::MESI_COMMERCIALI:
                VALORE = MESI_COMMERCIALI();
                break;
            case UNITA_DI_TEMPO::ANNI:
                VALORE = ANNI();
                break;
            case UNITA_DI_TEMPO::ANNI_COMMERCIALI:
                VALORE = ANNI_COMMERCIALI();
                break;
        }
        this->UNITA=UNITA;
    }
    uint64_t RESTO(){uint64_t R=REST; REST=0; return R;}
    void operator=(const TEMPO &T){UNITA=T.UNITA; VALORE=T.VALORE;}
    boolean operator==(const TEMPO &B){if(VALORE == B.VALORE && UNITA == B.UNITA){return 1;} return 0;}
    TEMPO operator+(const TEMPO &B){B.CONVERTI_IN(UNITA); TEMPO T(VALORE+B.VALORE,UNITA); return T;}
    TEMPO operator-(const TEMPO &B){B.CONVERTI_IN(UNITA); TEMPO T(VALORE-B.VALORE,UNITA); return T;}
    TEMPO operator*(const TEMPO &B){B.CONVERTI_IN(UNITA); TEMPO T(VALORE*B.VALORE,UNITA); return T;}
    TEMPO operator/(const TEMPO &B){B.CONVERTI_IN(UNITA); TEMPO T(VALORE/B.VALORE,UNITA); return T;}
    TEMPO operator%(const TEMPO &B){B.CONVERTI_IN(UNITA); TEMPO T(VALORE%B.VALORE,UNITA); return T;}
    boolean operator>(const TEMPO &B){B.CONVERTI_IN(UNITA); if(VALORE > B.VALORE){return 1;} return 0;}
    boolean operator<(const TEMPO &B){B.CONVERTI_IN(UNITA); if(VALORE < B.VALORE){return 1;} return 0;}
    boolean operator>=(const TEMPO &B){B.CONVERTI_IN(UNITA); if(VALORE >= B.VALORE){return 1;} return 0;}
    boolean operator<=(const TEMPO &B){B.CONVERTI_IN(UNITA); if(VALORE <= B.VALORE){return 1;} return 0;}
    TEMPO(uint64_t VALORE,UNITA_DI_TEMPO UNITA){this->UNITA=UNITA; this->VALORE=VALORE;}
    TEMPO(){}
};

void ASPETTA(uint64_t VALORE,UNITA_DI_TEMPO UNITA){TEMPO T(VALORE,UNITA); delayMicroseconds(T.MICROSECONDI());}

struct ORARIO{
protected:
 uint64_t NANOSEC,MICROSEC,MILLISEC,SEC,O,M;
public:

void ORE(uint64_t ORE){O = ORE;}
    
void MINUTI(uint64_t MINUTI){
 TEMPO T(MINUTI,MINUTI);
 if(MINUTI>59){
    O += T.ORE();
    M += T.RESTO();
    }
 else{M += MINUTI;}
}

void SECONDI(uint64_t SECONDI){
TEMPO T(SECONDI,SECONDI);
if(SECONDI > 59){MINUTI(T.MINUTI()); SEC += T.RESTO();}
else{SEC += T.VALORE;}
}

void MILLISECONDI(uint64_t MILLISECONDI){
TEMPO T(MILLISECONDI,MILLISECONDI);
if(MILLISECONDI > 999){SECONDI(T.SECONDI()); MILLISEC += T.RESTO();}
else{MILLISEC += T.VALORE;}
}

void MICROSECONDI(uint64_t MICROSECONDI){
TEMPO T(MICROSECONDI,MICROSECONDI);
if(MICROSECONDI > 999){MILLISECONDI(T.MILLISECONDI()); MICROSEC += T.RESTO();}
else{MICROSEC += T.VALORE;}
}
    
void NANOSECONDI(uint64_t NANOSECONDI){
TEMPO T(NANOSECONDI,NANOSECONDI);
if(NANOSECONDI > 999){MICROSECONDI(T.MICROSECONDI()); NANOSEC += T.RESTO();}
else{NANOSEC += T.VALORE;}
}
      
uint64_t  NANOSECONDI(){return NANOSEC;}
uint64_t  MICROSECONDI(){return MICROSEC;}
uint64_t  MILLISECONDI(){return MILLISEC;}
uint64_t  SECONDI(){return SEC;}
uint64_t  MINUTI(){return M;}
uint64_t  ORE(){return O;}
ORARIO(){}
ORARIO(uint64_t SECONDI,uint64_t MINUTI,uint64_t ORE){this->ORE(ORE); this->MINUTI(MINUTI); this->SECONDI(SECONDI);}
ORARIO(uint64_t NANOSECONDI,uint64_t MICROSECONDI,uint64_t MILLISECONDI,uint64_t SECONDI,uint64_t MINUTI,uint64_t ORE)
{this->ORE(ORE); this->MINUTI(MINUTI); this->SECONDI(SECONDI); this->MILLISECONDI(MILLISECONDI); this->MICROSECONDI(MICROSECONDI); this->NANOSECONDI(NANOSECONDI);}
ORARIO(TEMPO TEMPO_DA_IMPOSTARE){
this->ORE(TEMPO_DA_IMPOSTARE.ORE()); this->MINUTI(TEMPO_DA_IMPOSTARE.MINUTI()); this->SECONDI(TEMPO_DA_IMPOSTARE.SECONDI());
this->MILLISECONDI(TEMPO_DA_IMPOSTARE.MILLISECONDI()); this->MICROSECONDI(TEMPO_DA_IMPOSTARE.MICROSECONDI()); this->NANOSECONDI(TEMPO_DA_IMPOSTARE.NANOSECONDI());
}
};

class DATA_F{
    DATA_F(){}
};

class CRONOMETRO{
protected:
boolean CRONOMETRO_ATTIVO;
TEMPO TI = TEMPO(0,MICROSECONDI);
TEMPO TEMPO_PASS;
UNITA_DI_TEMPO UNITA_DI_TEMPO_CRONOMETRO=MICROSECONDI;
public:
void IMPOSTA_UNITA_DI_TEMPO(UNITA_DI_TEMPO UNITA){UNITA_DI_TEMPO_CRONOMETRO = UNITA;}
CRONOMETRO(UNITA_DI_TEMPO UNITA){IMPOSTA_UNITA_DI_TEMPO(UNITA);}
void AVVIA(){CRONOMETRO_ATTIVO=1; TI.VALORE = micros();}
void STOPPA(){CRONOMETRO_ATTIVO=0;}
TEMPO TEMPO_PASSATO(){
if(CRONOMETRO_ATTIVO){
TEMPO_PASS = TEMPO(micros()-TI.VALORE,MICROSECONDI);
TEMPO_PASS.CONVERTI_IN(UNITA_DI_TEMPO_CRONOMETRO);
return TEMPO_PASS;
}
else{return TEMPO(0,UNITA_DI_TEMPO_CRONOMETRO);}
}
};

class OROLOGIO_VIRTUALE:CRONOMETRO{
ORARIO O;
OROLOGIO_VIRTUALE(uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA):CRONOMETRO(MICROSECONDI){O=ORARIO(SECONDI,MINUTI,ORA);}
OROLOGIO_VIRTUALE(uint64_t NANOSECONDI,uint64_t MICROSECONDI,uint64_t MILLISECONDI,uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA):CRONOMETRO(MICROSECONDI){
O=ORARIO(NANOSECONDI,MICROSECONDI,MILLISECONDI,SECONDI,MINUTI,ORA);
}
    ORARIO LEGGI_ORARIO(){O = ORARIO(TEMPO_PASSATO()); return O;}
};

enum TIPO_TIMER{NON_BLOCCANTE,BLOCCANTE};
class TIMER:CRONOMETRO{
protected:
  TEMPO PERIODO;
  TIPO_TIMER T_TIMER=NON_BLOCCANTE;
  boolean ABILITAT;
  boolean T_INIZIALIZZATO;
public:
boolean INIZIALIZZATO(){return T_INIZIALIZZATO;}
void ABILITA(){if(T_TIMER==NON_BLOCCANTE){AVVIA(); ABILITAT=1;}}
boolean ABILITATO(){return ABILITAT;}
void DISABILITA(){STOPPA(); ABILITAT=0;}
TEMPO TEMPO_PASSATO_FINO_AD_ORA(){return TEMPO_PASSATO();}
void IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(uint64_t PERIODO,UNITA_DI_TEMPO UNITA){
IMPOSTA_UNITA_DI_TEMPO(UNITA);
this->PERIODO = TEMPO(PERIODO,UNITA);
this->PERIODO.CONVERTI_IN(MICROSECONDI);
}
void IMPOSTA_TIPO_TIMER(TIPO_TIMER TIPO){ T_TIMER=TIPO;}
boolean STOP(){
    switch(T_TIMER){
        case NON_BLOCCANTE:
            if(TEMPO_PASSATO()>=PERIODO){DISABILITA(); return 1;}
            return 0;
        case BLOCCANTE:
            ASPETTA(PERIODO.VALORE,PERIODO.UNITA);
            return 1;
    }
}
TIMER():CRONOMETRO(MICROSECONDI){}
TIMER(uint64_t PERIODO,UNITA_DI_TEMPO UNITA):CRONOMETRO(UNITA){IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(PERIODO,UNITA); T_INIZIALIZZATO=1;}
TIMER(uint64_t PERIODO,UNITA_DI_TEMPO UNITA, TIPO_TIMER TIPO):CRONOMETRO(UNITA){
 IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(PERIODO,UNITA);
 IMPOSTA_TIPO_TIMER(TIPO);
 T_INIZIALIZZATO=1;
}
};

class CICLO_TIMER:TIMER{
public:
  CICLO_TIMER(uint64_t PERIODO,UNITA_DI_TEMPO UNITA):TIMER(PERIODO,UNITA){}
  CICLO_TIMER(uint64_t PERIODO,UNITA_DI_TEMPO UNITA,TIPO_TIMER TIPO):TIMER(PERIODO,UNITA,TIPO){}
  CICLO_TIMER():TIMER(){}
boolean INIZIALIZZATO(){return TIMER::INIZIALIZZATO();}
boolean TICK(){
if(!ABILITATO()){ABILITA();}
if(STOP()){return 1;}
return 0;
}
};

enum MODALITA_RESISTENZA{RESISTENZA_ESTERNA,PULLUP,PULLDOWN};
enum TIPO_DIGITALE{LOGICA_NORMALE,LOGICA_INVERSA};
class ENTRATA{
protected:
    uint8_t PIN;
    TIPO_DIGITALE M_LETTURA_DIGITALE=LOGICA_NORMALE;
    MODALITA_RESISTENZA M_RESISTENZA=MODALITA_RESISTENZA::RESISTENZA_ESTERNA;
public:
    void RESISTENZA_ESTERNA(){M_RESISTENZA=MODALITA_RESISTENZA::RESISTENZA_ESTERNA; pinMode(PIN,INPUT);}
    void PULLUP(){M_RESISTENZA=MODALITA_RESISTENZA::PULLUP; pinMode(PIN,INPUT_PULLUP);}
    void PULLDOWN(){M_RESISTENZA=MODALITA_RESISTENZA::PULLDOWN; digitalWrite(PIN,0);}
protected:
    void IMPOSTA_PIN(uint8_t PIN){this->PIN=PIN; RESISTENZA_ESTERNA();}
    void IMPOSTA_MODALITA_RESISTENZA(MODALITA_RESISTENZA M_RESISTENZA){
     switch(M_RESISTENZA){
         case MODALITA_RESISTENZA::RESISTENZA_ESTERNA:
            RESISTENZA_ESTERNA();
            break;
         case MODALITA_RESISTENZA::PULLUP:
            PULLUP();
            break;
         case MODALITA_RESISTENZA::PULLDOWN:
            PULLDOWN();
            break;
           }
    }
    void IMPOSTA_MODALITA_LETTURA_DIGITALE(TIPO_DIGITALE M_LETTURA_DIGITALE){
        this->M_LETTURA_DIGITALE=M_LETTURA_DIGITALE;
    }
public:
    ENTRATA(){}
    ENTRATA(uint8_t PIN){IMPOSTA_PIN(PIN);}
    ENTRATA(uint8_t PIN,MODALITA_RESISTENZA M_RESISTENZA){
     IMPOSTA_MODALITA_RESISTENZA(M_RESISTENZA); IMPOSTA_PIN(PIN);
    }
    ENTRATA(uint8_t PIN,TIPO_DIGITALE M_LETTURA_DIGITALE){
     IMPOSTA_MODALITA_LETTURA_DIGITALE(M_LETTURA_DIGITALE); IMPOSTA_PIN(PIN);
    }
    ENTRATA(uint8_t PIN,MODALITA_RESISTENZA M_RESISTENZA,TIPO_DIGITALE M_LETTURA_DIGITALE){
     IMPOSTA_MODALITA_RESISTENZA(M_RESISTENZA);
     IMPOSTA_MODALITA_LETTURA_DIGITALE(M_LETTURA_DIGITALE);
     IMPOSTA_PIN(PIN);
    }
    boolean LETTURA_DIGITALE(){
    boolean L=digitalRead(PIN);
    switch(M_LETTURA_DIGITALE){
        case LOGICA_NORMALE:
            return L;
            break;
        case LOGICA_INVERSA:
            return !L;
            break;
        }
    }
    uint16_t LETTURA_ANALOGICA(){return analogRead(PIN);}
};

enum MEMORIZZA_STATO:boolean{NON_SALVARE_LO_STATO=0,SALVA_STATO=1};
class USCITA{
protected:
    uint8_t PIN;
    CICLO_TIMER LAMP;
    TIMER PERIODO;
    TIPO_DIGITALE TIPO_D=LOGICA_NORMALE;
    MEMORIZZA_STATO SALVA=NON_SALVARE_LO_STATO;
    void IMPOSTA_PIN(uint8_t PIN){this->PIN=PIN; pinMode(PIN,OUTPUT);}
public:
    void IMPOSTA_STATO(uint8_t PERCENTUALE){
     if(PERCENTUALE==100){
        switch(TIPO_D){
            case LOGICA_NORMALE:
                digitalWrite(PIN,1);
                break;
            case LOGICA_INVERSA:
                digitalWrite(PIN,0);
                break;
            }
        }
    else{analogWrite(PIN,(PERCENTUALE*255)/100);}
    if(SALVA){EEPROM.update(PIN,PERCENTUALE);}
    }
private:
    void INIZIALIZZA_PIN(uint8_t PIN){IMPOSTA_PIN(PIN); IMPOSTA_STATO(EEPROM.read(PIN));};
public:
    void IMPOSTA_STATO_ANALOGICO(uint8_t STATO){IMPOSTA_STATO((STATO*100)/255);}
    USCITA(){}
    USCITA(uint8_t PIN){IMPOSTA_PIN(PIN);}
    USCITA(uint8_t PIN,TIPO_DIGITALE TIPO_D){this->TIPO_D=TIPO_D; INIZIALIZZA_PIN(PIN);}
    USCITA(uint8_t PIN,MEMORIZZA_STATO SALVA){this->SALVA=SALVA; INIZIALIZZA_PIN(PIN);}
    USCITA(uint8_t PIN,TIPO_DIGITALE TIPO_D,MEMORIZZA_STATO SALVA){
     this->TIPO_D=TIPO_D;
     this->SALVA=SALVA;
     INIZIALIZZA_PIN(PIN);
    }
    void ACCENDI(){IMPOSTA_STATO(100);}
    void SPEGNI(){IMPOSTA_STATO(0);}
    void IMPOSTA_STATO_IN_RITARDO(uint8_t PERCENTUALE,uint64_t RITARDO,UNITA_DI_TEMPO UNITA){
        ASPETTA(RITARDO,UNITA);
        IMPOSTA_STATO(PERCENTUALE);
    }
    void IMPOSTA_STATO_IN_RITARDO_CON_TIMER(uint8_t PERCENTUALE,uint64_t RITARDO,UNITA_DI_TEMPO UNITA){
        if(PERIODO.ABILITATO()){PERIODO=TIMER(RITARDO,UNITA);}
        if(PERIODO.STOP()){IMPOSTA_STATO(PERCENTUALE);}
    }
    void ACCENDI_CON_DISSOLVENZA(uint8_t PERCENTUALE_MASSIMA,uint16_t LENTEZZA,UNITA_DI_TEMPO UNITA){
        for(uint8_t P;P<PERCENTUALE_MASSIMA;P++){
            ASPETTA(LENTEZZA,UNITA);
            IMPOSTA_STATO(P);
        }
    }
    void SPEGNI_CON_DISSOLVENZA(uint8_t PERCENTUALE_MASSIMA,uint16_t LENTEZZA,UNITA_DI_TEMPO UNITA){
        for(uint8_t P=PERCENTUALE_MASSIMA;P>0;P--){
            ASPETTA(LENTEZZA,UNITA);
            IMPOSTA_STATO(P);
        }
    }
    void INVERTI_STATO(){digitalWrite(PIN,!digitalRead(PIN));}
    void LAMPEGGIO(uint16_t PERIODO,UNITA_DI_TEMPO UNITA){
     if(!LAMP.INIZIALIZZATO()){LAMP = CICLO_TIMER(PERIODO,UNITA);}
     if(LAMP.TICK()){INVERTI_STATO();}
    }
    void PULSAZIONE(uint8_t PERCENTUALE_MASSIMA,uint16_t PERIODO,UNITA_DI_TEMPO UNITA){
     ACCENDI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA,PERIODO,UNITA);
     SPEGNI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA,PERIODO,UNITA);
    }
};

class LED:public USCITA {
public:
    LED(){}
    LED(uint8_t PIN):USCITA(PIN){}
    LED(uint8_t PIN,MEMORIZZA_STATO SALVA):USCITA(PIN,SALVA){}
};

struct VALORI_RGB{
    uint8_t VERDE,ROSSO,BLU;
    VALORI_RGB(){}
    VALORI_RGB(uint8_t VERDE,uint8_t ROSSO,uint8_t BLU){
        this->VERDE=VERDE;
        this->ROSSO=ROSSO;
        this->ROSSO=ROSSO;
    }
    void IMPOSTA_LUMINOSITA(uint8_t PERCENTUALE){
        VERDE=(PERCENTUALE*100/VERDE);
        ROSSO=(PERCENTUALE*100/ROSSO);
        BLU=(PERCENTUALE*100/BLU);
    }
};
const VALORI_RGB COLORE_VERDE=VALORI_RGB(0,128,0),COLORE_ROSSO=VALORI_RGB(255,0,0);
const VALORI_RGB COLORE_BLU=VALORI_RGB(0,0,255),COLORE_BIANCO=VALORI_RGB(255,255,255);
class LED_RGB{
public:
    LED VERDE,ROSSO,BLU;
    VALORI_RGB COLORE;
    void IMPOSTA_COLORE(VALORI_RGB COLORE){
        VERDE.IMPOSTA_STATO_ANALOGICO(COLORE.VERDE);
        ROSSO.IMPOSTA_STATO_ANALOGICO(COLORE.ROSSO);
        BLU.IMPOSTA_STATO_ANALOGICO(COLORE.BLU);
    }
    LED_RGB(){}
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU){
     VERDE = LED(PIN_VERDE);
     ROSSO = LED(PIN_ROSSO);
     BLU = LED(PIN_BLU);
    }
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU,VALORI_RGB COLORE){
     VERDE = LED(PIN_VERDE);
     ROSSO = LED(PIN_ROSSO);
     BLU = LED(PIN_BLU);
     this->COLORE=COLORE;
     IMPOSTA_COLORE(COLORE);
    }
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU,MEMORIZZA_STATO SALVA){
     VERDE = LED(PIN_VERDE,SALVA);
     ROSSO = LED(PIN_ROSSO,SALVA);
     BLU = LED(PIN_BLU,SALVA);
    }
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU,MEMORIZZA_STATO SALVA,VALORI_RGB COLORE){
     VERDE = LED(PIN_VERDE,SALVA);
     ROSSO = LED(PIN_ROSSO,SALVA);
     BLU = LED(PIN_BLU,SALVA);
     this->COLORE=COLORE;
     IMPOSTA_COLORE(COLORE);
    }
    void LAMPEGGIO(uint16_t PERIODO,UNITA_DI_TEMPO UNITA){
        VERDE.SPEGNI();
        ROSSO.SPEGNI();
        ROSSO.SPEGNI();
        ASPETTA(PERIODO,UNITA);
        IMPOSTA_COLORE(COLORE);
    }
    void ACCENDI_CON_DISSOLVENZA(uint8_t PERCENTUALE_MASSIMA,uint16_t LENTEZZA,UNITA_DI_TEMPO UNITA){
        VALORI_RGB COLORE_CAMBIATO = this->COLORE;
        for(uint8_t P;P<PERCENTUALE_MASSIMA;P++){
            COLORE_CAMBIATO.IMPOSTA_LUMINOSITA(100+P);
            IMPOSTA_COLORE(COLORE_CAMBIATO);
        }
    }
    void SPEGNI_CON_DISSOLVENZA(uint8_t PERCENTUALE_MASSIMA,uint16_t LENTEZZA,UNITA_DI_TEMPO UNITA){
        VALORI_RGB COLORE_CAMBIATO = this->COLORE;
        for(uint8_t P;P>0;P--){
            COLORE_CAMBIATO.IMPOSTA_LUMINOSITA(100-P);
            IMPOSTA_COLORE(COLORE_CAMBIATO);
        }
    }
    void PULSAZIONE(uint8_t PERCENTUALE_MASSIMA,uint16_t LENTEZZA,UNITA_DI_TEMPO UNITA){
     ACCENDI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA,LENTEZZA,UNITA);
     SPEGNI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA,LENTEZZA,UNITA);
    }
    
};

class RELE:public USCITA{
 public:
  RELE(uint8_t PIN,TIPO_DIGITALE TIPO):USCITA(PIN,TIPO){}
  RELE(uint8_t PIN,TIPO_DIGITALE TIPO,MEMORIZZA_STATO SALVA_STATO):USCITA(PIN,TIPO,SALVA_STATO){}
  void ACCESO(){ACCENDI();}
  void SPENTO(){SPEGNI();}
  void INVERTI_STATO(){USCITA::INVERTI_STATO();}
  void LAMPEGGIO(uint16_t PERIODO,UNITA_DI_TEMPO UNITA){USCITA::LAMPEGGIO(PERIODO,UNITA);}
};

enum TIPO_TERMOSTATO{RISCALDAMENTO,RAFFREDDAMENTO};
class TERMOSTATO:RELE {
  protected:
   TIPO_TERMOSTATO TIPO_T;
  public:
  uint8_t SOGLIA_TEMPERATURA=20;
TERMOSTATO(uint8_t PIN_R,TIPO_DIGITALE TIPORELE,TIPO_TERMOSTATO TIPO_T):RELE(PIN_R,TIPORELE){this->TIPO_T=TIPO_T;}
void FUNZIONE_TERMOSTATO(uint8_t TEMPERATURA_ATTUALE){
 switch(TIPO_T){
  case RISCALDAMENTO:
   if(TEMPERATURA_ATTUALE<SOGLIA_TEMPERATURA){ACCESO();} else{SPENTO();}
   break;
  case RAFFREDDAMENTO:
   if(TEMPERATURA_ATTUALE>SOGLIA_TEMPERATURA){ACCESO();} else {SPENTO();}
}
}
};

class PULSANTE:ENTRATA,CICLO_TIMER{
 protected:
  boolean STATO_PRECEDENTE;
 public:
    PULSANTE(){}
    PULSANTE(uint8_t PIN,uint64_t RITARDO,UNITA_DI_TEMPO UNITA):ENTRATA(PIN),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint64_t RITARDO,UNITA_DI_TEMPO UNITA,MODALITA_RESISTENZA M_RESISTENZA):ENTRATA(PIN,M_RESISTENZA),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint64_t RITARDO,UNITA_DI_TEMPO UNITA,TIPO_DIGITALE M_LETTURA_DIGITALE):ENTRATA(PIN,M_LETTURA_DIGITALE),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint64_t RITARDO,UNITA_DI_TEMPO UNITA,MODALITA_RESISTENZA M_RESISTENZA,
    TIPO_DIGITALE M_LETTURA_DIGITALE):ENTRATA(PIN,M_RESISTENZA,M_LETTURA_DIGITALE),CICLO_TIMER(RITARDO,UNITA){}
  boolean CLICCATO(){
   if(TICK()){
     if(STATO_PRECEDENTE && LETTURA_DIGITALE()){
       STATO_PRECEDENTE=0;
       return 1;
      }
   }
   if(LETTURA_DIGITALE() && STATO_PRECEDENTE==0){STATO_PRECEDENTE=1;}
   return 0;
  }
  void RESISTENZA_ESTERNA(){ENTRATA::RESISTENZA_ESTERNA();}
  void PULLUP(){ENTRATA::PULLUP();}
  void PULLDOWN(){ENTRATA::PULLDOWN();}
};

class FOTORESISTORE:ENTRATA,CICLO_TIMER{
protected:
uint16_t SOGLIA_ACCENSIONE;
uint16_t SOGLIA_SPEGNIMENTO;
boolean ULTIMO_CONTROLLO_ESEGUITO;
public:
FOTORESISTORE(uint8_t PIN,uint16_t SOGLIA_ACCENSIONE,uint16_t SOGLIA_SPEGNIMENTO,uint64_t RITARDO,UNITA_DI_TEMPO UNITA):ENTRATA(PIN),CICLO_TIMER(RITARDO,UNITA){
this->SOGLIA_ACCENSIONE = SOGLIA_ACCENSIONE;
this->SOGLIA_SPEGNIMENTO = SOGLIA_SPEGNIMENTO;
}
uint16_t LEGGI_FOTORESISTORE(){return LETTURA_ANALOGICA();}
boolean CONTROLLO(){
if(TICK()){
if(LEGGI_FOTORESISTORE()>=SOGLIA_ACCENSIONE){ULTIMO_CONTROLLO_ESEGUITO=1; return 1;}
if(LEGGI_FOTORESISTORE()<=SOGLIA_ACCENSIONE && LEGGI_FOTORESISTORE()>=SOGLIA_SPEGNIMENTO){ return ULTIMO_CONTROLLO_ESEGUITO;}
ULTIMO_CONTROLLO_ESEGUITO=0;
return 0;
}
return ULTIMO_CONTROLLO_ESEGUITO;
}
};

class CREPUSCOLARE:RELE,FOTORESISTORE{
public:
CREPUSCOLARE(uint8_t PIN_FOTORESISTORE,uint16_t SOGLIA_ACCENSIONE,uint16_t SOGLIA_SPEGNIMENTO,uint64_t RITARDO,UNITA_DI_TEMPO UNITA,
uint8_t PIN_RELE,TIPO_DIGITALE TIPORELE):FOTORESISTORE(PIN_FOTORESISTORE,SOGLIA_ACCENSIONE,SOGLIA_SPEGNIMENTO,RITARDO,UNITA),
RELE(PIN_RELE,TIPORELE){}
void FUNZIONE_CREPUSCOLARE(){
  if(CONTROLLO()){ACCESO();}
  else{SPENTO();}
}
};

class INGRESSO_MONITORATO{
protected:
 uint16_t FINECORSA_APERTURA;
 uint16_t FINECORSA_CHIUSURA;
public:
   virtual boolean APERTO()=0;
   virtual boolean CHIUSO()=0;
   INGRESSO_MONITORATO(uint16_t FINECORSA_APERTURA,uint16_t FINECORSA_CHIUSURA){
    this->FINECORSA_APERTURA = FINECORSA_APERTURA;
    this->FINECORSA_CHIUSURA = FINECORSA_CHIUSURA;
    }
   INGRESSO_MONITORATO(){}
};

class INGRESSO_FISICO:INGRESSO_MONITORATO{
 protected:
  PULSANTE PULSANTE_FINECORSA_APERTURA;
  PULSANTE PULSANTE_FINECORSA_CHIUSURA;
 public:
  INGRESSO_FISICO(uint8_t PIN_FINECORSA_APERTURA,uint8_t PIN_FINECORSA_CHIUSURA,uint64_t RITARDO_FINECORSA1,UNITA_DI_TEMPO UNITA_FINECORSA1,
  uint64_t RITARDO_FINECORSA2,UNITA_DI_TEMPO UNITA_FINECORSA2):INGRESSO_MONITORATO(){
  PULSANTE_FINECORSA_APERTURA = PULSANTE(PIN_FINECORSA_APERTURA,RITARDO_FINECORSA1,UNITA_FINECORSA1);
  PULSANTE_FINECORSA_CHIUSURA = PULSANTE(PIN_FINECORSA_CHIUSURA,RITARDO_FINECORSA2,UNITA_FINECORSA2);
  }
  INGRESSO_FISICO(uint8_t PIN_FINECORSA_APERTURA,uint8_t PIN_FINECORSA_CHIUSURA,uint64_t RITARDO_FINECORSA,UNITA_DI_TEMPO UNITA_FINECORSA):
  INGRESSO_MONITORATO(){
  PULSANTE_FINECORSA_APERTURA = PULSANTE(PIN_FINECORSA_APERTURA,RITARDO_FINECORSA,UNITA_FINECORSA);
  PULSANTE_FINECORSA_CHIUSURA = PULSANTE(PIN_FINECORSA_CHIUSURA,RITARDO_FINECORSA,UNITA_FINECORSA);
  }
 boolean APERTO() override {return PULSANTE_FINECORSA_APERTURA.CLICCATO();}
 boolean CHIUSO() override {return PULSANTE_FINECORSA_CHIUSURA.CLICCATO();}
};

enum STATO_DEL_MOVIMENTO:uint8_t{CHIUSURA=0,APERTURA=1};
class STATO_MOVIMENTO{
 public:
  uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO;
  void MEMORIZZA_STATO(STATO_DEL_MOVIMENTO STATO){
   EEPROM.update(INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO,STATO);
   }
  virtual void APRI()=0;
  virtual void CHIUDI()=0;
  void CONTROLLO_STATO_MOVIMENTO(){
    STATO_DEL_MOVIMENTO STATO;
    EEPROM.get(INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO,STATO);
      if(STATO==APERTURA){APRI();
          Serial.end();
          Serial.begin(9600);
          Serial.println(STATO);
      }
      else{CHIUDI();}
    }
    STATO_MOVIMENTO(uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO){
    this->INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO=INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO;
    }
};

class INGRESSO_MOTORIZZATO:public INGRESSO_MONITORATO,public STATO_MOVIMENTO{
public:
    INGRESSO_MOTORIZZATO(uint16_t FINECORSA_APERTURA,uint16_t FINECORSA_CHIUSURA,uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO):
    INGRESSO_MONITORATO(FINECORSA_APERTURA,FINECORSA_CHIUSURA),
    STATO_MOVIMENTO(INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO){}
};

class MOTORE_SWIPING{
public:
    CICLO_TIMER C;
    uint16_t GRADI_AVANTI;
    uint16_t GRADI_INDIETRO;
    virtual uint16_t POSIZIONE_CORRENTE()=0;
    virtual void SWIPE_AVANTI()=0;
    virtual void SWIPE_INDIETRO()=0;
    void SWIPING(uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
    if(!C.INIZIALIZZATO()){C = CICLO_TIMER(TEMPO_DA_FERMO,UNITA);}
     if(C.TICK()){
     if(GRADI_AVANTI>GRADI_INDIETRO){
     if(POSIZIONE_CORRENTE()<GRADI_AVANTI){SWIPE_AVANTI();}
     else if(POSIZIONE_CORRENTE()>GRADI_INDIETRO){SWIPE_INDIETRO();}
     }
     else{
     if(POSIZIONE_CORRENTE()>GRADI_AVANTI){SWIPE_AVANTI();}
     else if(POSIZIONE_CORRENTE()<GRADI_INDIETRO){SWIPE_INDIETRO();}
     }
     }
    }
    MOTORE_SWIPING(){}
};

class SERVOMOTORE:Servo,MOTORE_SWIPING{
 protected:
    uint8_t PIN;
    uint8_t INDIRIZZO_EEPROM_GRADI;
    uint16_t PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI;
    void INIZIALIZZA_SE_NON_INZIALIZZATO(){if(!attached()){attach(PIN); write(POSIZIONE_CORRENTE()); delay(1);}}
    void SCRIVI_POSIZIONE(uint8_t GRADI){
    if(GRADI>180){GRADI=180;}
    INIZIALIZZA_SE_NON_INZIALIZZATO();
    write(GRADI);
    EEPROM.update(INDIRIZZO_EEPROM_GRADI,GRADI);
  }
  void AUMENTA_POSIZIONE(uint8_t GRADI,uint16_t PERIODO_IN_MILLISECONDI){
    for(uint16_t P=POSIZIONE_CORRENTE();P<=GRADI;P++){
    SCRIVI_POSIZIONE(P);
    delay(PERIODO_IN_MILLISECONDI);
    }
  }
  void DIMINUISCI_POSIZIONE(uint8_t GRADI,uint16_t PERIODO_IN_MILLISECONDI){
    for(int16_t P=POSIZIONE_CORRENTE();P>=GRADI;P--){
    SCRIVI_POSIZIONE(P);
    delay(PERIODO_IN_MILLISECONDI);
    }
  }
  void SWIPE_AVANTI()override{IMPOSTA_POSIZIONE(GRADI_AVANTI, PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI);}
  void SWIPE_INDIETRO()override{IMPOSTA_POSIZIONE(GRADI_INDIETRO, PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI);}
public:
  void IMPOSTA_POSIZIONE(uint16_t GRADI,uint16_t PERIODO_IN_MILLISECONDI){
    if(PERIODO_IN_MILLISECONDI>0){
    AUMENTA_POSIZIONE(GRADI,PERIODO_IN_MILLISECONDI);
    DIMINUISCI_POSIZIONE(GRADI,PERIODO_IN_MILLISECONDI);
     }
     else{SCRIVI_POSIZIONE(GRADI);}
    }
    uint16_t POSIZIONE_CORRENTE()override{return EEPROM.read(INDIRIZZO_EEPROM_GRADI);}
    void SWIPING(uint8_t GRADI_AVANTI, uint8_t GRADI_INDIETRO, uint16_t PERIODO_SPOSTAMENTO_IN_MILLISECONDI,uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
    this->GRADI_AVANTI = GRADI_AVANTI;
    this->GRADI_INDIETRO = GRADI_INDIETRO;
    PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI = PERIODO_SPOSTAMENTO_IN_MILLISECONDI;
    MOTORE_SWIPING::SWIPING(TEMPO_DA_FERMO,UNITA);
    }
    SERVOMOTORE(uint8_t PIN):Servo(),MOTORE_SWIPING(){
    this->INDIRIZZO_EEPROM_GRADI=PIN;
    this->PIN = PIN;
    /*NON SI PUO USARE LA FUNZIONE "attach" PRIMA DEL SETUP,
    IPOTIZZO CHE PRIMA DEL SETUP NON VENGONO INIZIALIZZATE LE FUNZIONI PRINCIPALI DELL'AMBIENTE DI SVILUPPO,
    QUINDI VERRA ESEGUITO LA PRIMA VOLTA CHE SI USA IL SERVOMOTORE*/
    }
};

class SERVO_INGRESSO:SERVOMOTORE,INGRESSO_MOTORIZZATO{
  protected:
   uint16_t RITARDO_MOVIMENTO_IN_MILLISECONDI;
  public:
   void APRI() override {
    MEMORIZZA_STATO(APERTURA);
    IMPOSTA_POSIZIONE(FINECORSA_APERTURA,RITARDO_MOVIMENTO_IN_MILLISECONDI);
   }
   void CHIUDI() override {
    MEMORIZZA_STATO(CHIUSURA);
    IMPOSTA_POSIZIONE(FINECORSA_CHIUSURA,RITARDO_MOVIMENTO_IN_MILLISECONDI);
   }
   boolean APERTO() override {return POSIZIONE_CORRENTE()==FINECORSA_APERTURA;}
   boolean CHIUSO() override {return POSIZIONE_CORRENTE()==FINECORSA_CHIUSURA;}
   SERVO_INGRESSO(uint8_t PIN,uint16_t POSIZIONE_APERTURA,uint16_t POSIZIONE_CHIUSURA,uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO,
   uint16_t RITARDO_MOVIMENTO_IN_MILLISECONDI):SERVOMOTORE(PIN),
   INGRESSO_MOTORIZZATO(POSIZIONE_APERTURA,POSIZIONE_CHIUSURA,INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO){
   this->RITARDO_MOVIMENTO_IN_MILLISECONDI = RITARDO_MOVIMENTO_IN_MILLISECONDI; CONTROLLO_STATO_MOVIMENTO();}
};

class MOTORE_STEPPER_BASE:MOTORE_SWIPING{
public:
 uint16_t PASSI_MASSIMI;
 uint16_t INDIRIZZO_POSIZIONE_EEPROM;
 uint8_t VELOCITA;
 void MEMORIZZA_PASSI(uint16_t PASSI){EEPROM.put(INDIRIZZO_POSIZIONE_EEPROM,PASSI);}
 void IMPOSTA_VELOCITA(uint8_t VELOCITA){this->VELOCITA=VELOCITA;}
 MOTORE_STEPPER_BASE(uint16_t PASSI_MASSIMI,uint8_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_EEPROM){
 this->PASSI_MASSIMI=PASSI_MASSIMI;
 this->INDIRIZZO_POSIZIONE_EEPROM = INDIRIZZO_POSIZIONE_EEPROM;
 IMPOSTA_VELOCITA(VELOCITA);
 }
 uint16_t POSIZIONE_CORRENTE()override{
  uint16_t R;
  EEPROM.get(INDIRIZZO_POSIZIONE_EEPROM,R);
  return R;
 }
 virtual void PASSO()=0;
 virtual void SINISTRA()=0;
 virtual void DESTRA()=0;
 void PASSI(uint16_t PASSI){for(uint16_t P; P<PASSI; P++){PASSO();} MEMORIZZA_PASSI(PASSI);}
 uint16_t PASSI_AVANTI;
 uint16_t PASSI_INDIETRO;
 void SWIPE_AVANTI() override {PASSI(PASSI_AVANTI);}
 void SWIPE_INDIETRO() override {PASSI(PASSI_INDIETRO);}
 void SWIPING(uint16_t PASSI_AVANTI,uint16_t PASSI_INDIETRO,uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
  this->PASSI_AVANTI = PASSI_AVANTI;
  this->PASSI_INDIETRO = PASSI_INDIETRO;
  MOTORE_SWIPING::SWIPING(TEMPO_DA_FERMO,UNITA);
  }
};

class MOTORE_STEPPER:MOTORE_STEPPER_BASE{
private:
    uint8_t PIN_CONTROLLO_PASSO;
    uint8_t PIN_VERSO;
    boolean STATO_PIN_VERSO_DESTRA;
    void PASSO() override {
        digitalWrite(PIN_CONTROLLO_PASSO,HIGH);
        delay(10);
        digitalWrite(PIN_CONTROLLO_PASSO,LOW);
     }
public:
    MOTORE_STEPPER(uint8_t PIN_CONTROLLO_PASSO,uint8_t PIN_VERSO, boolean STATO_PIN_VERSO_DESTRA, uint16_t PASSI_MASSIMI,uint16_t INDIRIZZO_POSIZIONE_EEPROM,uint8_t VELOCITA):
    MOTORE_STEPPER_BASE(PASSI_MASSIMI,VELOCITA,INDIRIZZO_POSIZIONE_EEPROM){
     this->PIN_CONTROLLO_PASSO=PIN_CONTROLLO_PASSO;
     this->PIN_VERSO=PIN_VERSO;
     pinMode(PIN_CONTROLLO_PASSO,OUTPUT);
     pinMode(PIN_VERSO,OUTPUT);
     }
    void PASSI(uint16_t PASSI){MOTORE_STEPPER_BASE::PASSI(PASSI);}
    void DESTRA() override {digitalWrite(PIN_VERSO,STATO_PIN_VERSO_DESTRA);}
    void SINISTRA() override {digitalWrite(PIN_VERSO,!STATO_PIN_VERSO_DESTRA);}
};

class MOTORE_STEPPER_4_BOBINE:Stepper,public MOTORE_STEPPER_BASE{
protected:
    void PASSO() override{step(1);}
public:
    void IMPOSTA_VELOCITA(uint16_t VELOCITA){
    MOTORE_STEPPER_BASE::IMPOSTA_VELOCITA(VELOCITA);
    setSpeed(VELOCITA);
  }
    MOTORE_STEPPER_4_BOBINE(uint16_t PASSI_MASSIMI,uint8_t PIN_BOBINA1,uint8_t PIN_BOBINA2,uint8_t PIN_BOBINA3,uint8_t PIN_BOBINA4,uint16_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_EEPROM):
     MOTORE_STEPPER_BASE(PASSI_MASSIMI,VELOCITA,INDIRIZZO_POSIZIONE_EEPROM),
     Stepper(PASSI_MASSIMI,PIN_BOBINA1,PIN_BOBINA2,PIN_BOBINA3,PIN_BOBINA4){IMPOSTA_VELOCITA(VELOCITA);}
};

class STEPPER_INGRESSO_BASE:MOTORE_STEPPER_BASE,public INGRESSO_MOTORIZZATO {
   public:
    virtual uint16_t POSIZIONE_CORRENTE()=0;
    void APRI() override {
     MEMORIZZA_STATO(APERTURA);
     PASSI(FINECORSA_APERTURA);
    }
    void CHIUDI() override {
     MEMORIZZA_STATO(CHIUSURA);
     PASSI(FINECORSA_CHIUSURA);
    }
    boolean APERTO() override {return POSIZIONE_CORRENTE()==FINECORSA_APERTURA;}
    boolean CHIUSO() override {return POSIZIONE_CORRENTE()==FINECORSA_CHIUSURA;}
    void IMPOSTA_VELOCITA(uint16_t VELOCITA){MOTORE_STEPPER_BASE::IMPOSTA_VELOCITA(VELOCITA);}
    STEPPER_INGRESSO_BASE(uint16_t PASSI_MASSIMI,uint16_t PASSI_APERTURA,uint16_t PASSI_CHIUSURA,uint8_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_EEPROM,
    uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO):
    MOTORE_STEPPER_BASE(PASSI_MASSIMI,VELOCITA,INDIRIZZO_POSIZIONE_EEPROM),
    INGRESSO_MOTORIZZATO(PASSI_APERTURA,PASSI_CHIUSURA,INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO){}
};

class STEPPER_INGRESSO:public STEPPER_INGRESSO_BASE{
public:
    uint16_t POSIZIONE_CORRENTE() override {return STEPPER_INGRESSO_BASE::POSIZIONE_CORRENTE();}
    STEPPER_INGRESSO(uint8_t PIN_CONTROLLO_PASSO,uint8_t PIN_VERSO, boolean STATO_PIN_VERSO_DESTRA,uint16_t PASSI_MASSIMI,
    uint8_t VELOCITA,uint16_t PASSI_APERTURA,uint16_t PASSI_CHIUSURA):
    STEPPER_INGRESSO_BASE(PASSI_MASSIMI,PASSI_APERTURA,PASSI_CHIUSURA,VELOCITA,PIN_CONTROLLO_PASSO,PIN_VERSO){
     IMPOSTA_VELOCITA(VELOCITA);
     CONTROLLO_STATO_MOVIMENTO();
     }
};

class STEPPER_INGRESSO_4_BOBINE:public MOTORE_STEPPER_4_BOBINE,public STEPPER_INGRESSO_BASE{
  public:
    uint16_t POSIZIONE_CORRENTE() override {return MOTORE_STEPPER_4_BOBINE::POSIZIONE_CORRENTE();}
    STEPPER_INGRESSO_4_BOBINE(uint16_t PASSI_MASSIMI,uint8_t PIN_BOBINA1,uint8_t PIN_BOBINA2,uint8_t PIN_BOBINA3,uint8_t PIN_BOBINA4,
    uint16_t PASSI_APERTURA,uint16_t PASSI_CHIUSURA,uint8_t VELOCITA):
    MOTORE_STEPPER_4_BOBINE(PASSI_MASSIMI,VELOCITA,PIN_BOBINA1,PIN_BOBINA2,PIN_BOBINA3,PIN_BOBINA4,PIN_BOBINA1),
    STEPPER_INGRESSO_BASE(PASSI_MASSIMI,PASSI_APERTURA,PASSI_CHIUSURA,VELOCITA,PIN_BOBINA2,PIN_BOBINA3){CONTROLLO_STATO_MOVIMENTO();}
};

class DHT_F:DHT{
protected:
    boolean INIZIALIZZATO;
    void INIZIALIZZA_SE_NON_INZIALIZZATO(){if(!INIZIALIZZATO){begin();}}
public:
    DHT_F(uint8_t PIN,uint8_t TIPO):DHT(PIN,TIPO){}
    float LEGGI_TEMPERATURA(){
        INIZIALIZZA_SE_NON_INZIALIZZATO();
        return readTemperature();
    }
    float LEGGI_UMIDITA(){
        INIZIALIZZA_SE_NON_INZIALIZZATO();
        return readHumidity();
    }
};

class TASTIERA_A_MATRICE{
    
};

class ALLARME:TASTIERA_A_MATRICE{
    
};

#endif
