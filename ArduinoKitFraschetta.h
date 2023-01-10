#ifndef ArduinoKitFraschetta_h
#define ArduinoKitFraschetta_h
#include "EEPROM.h"
#include "Servo.h"
#include "Stepper.h"

enum UNITA_DI_TEMPO{NANOSECONDI,MICROSECONDI,MILLISECONDI,SECONDI,MINUTI,ORE,GIORNI,SETTIMANE,MESE_COMMERCIALE,ANNI,ANNI_COMMERCIALI};
struct TEMPO{
protected:
 uint_64_t RESTO;
public:
UNITA_DI_TEMPO UNITA
uint_64_t VALORE;
    
    uint_64_t NANOSECONDI(){
        switch(UNITA){
            case NANOSECONDI:
                RESTO=0;
                return VALORE;
            case MICROSECONDI:
                RESTO=0;
                return VALORE*1000;
            case MILLISECONDI:
                RESTO=0;
                return VALORE*1000000;
            case SECONDI:
                RESTO=0;
                return VALORE*1000000000;
            case MINUTI:
                RESTO=0;
                return VALORE*60000000000;
            case ORE:
                RESTO=0;
                return VALORE*3600000000000;
            case GIORNI:
                RESTO=0;
                return VALORE*8640000000000;
            case SETTIMANE:
                RESTO=0;
                return VALORE*60480000000000;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*259200000000000;
            case ANNI:
                RESTO=0;
                return VALORE*3153600000000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*3110400000000000;
        }
    }
    uint_64_t MICROSECONDI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                RESTO=0;
                return VALORE;
            case MILLISECONDI:
                RESTO=0;
                return VALORE*1000;
            case SECONDI:
                RESTO=0;
                return VALORE*1000000;
            case MINUTI:
                RESTO=0;
                return VALORE*60000000;
            case ORE:
                RESTO=0;
                return VALORE*3600000000;
            case GIORNI:
                RESTO=0;
                return VALORE*86400000000;
            case SETTIMANE:
                RESTO=0;
                return VALORE*604800000000;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*2592000000000;
            case ANNI:
                RESTO=0;
                return VALORE*31536000000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*31104000000000;
        }
    }
    uint_64_t MILLISECONDI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                RESTO=0;
                return VALORE;
            case SECONDI:
                RESTO=0;
                return VALORE*1000;
            case MINUTI:
                RESTO=0;
                return VALORE*60000;
            case ORE:
                RESTO=0;
                return VALORE*3600000;
            case GIORNI:
                RESTO=0;
                return VALORE*86400000;
            case SETTIMANE:
                RESTO=0;
                return VALORE*604800000;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*2592000000;
            case ANNI:
                RESTO=0;
                return VALORE*31536000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*31104000000;
        }
    }
    uint_64_t SECONDI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000000000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                RESTO=0;
                return VALORE;
            case MINUTI:
                RESTO=0;
                return VALORE*60;
            case ORE:
                RESTO=0;
                return VALORE*3600;
            case GIORNI:
                RESTO=0;
                return VALORE*86400;
            case SETTIMANE:
                RESTO=0;
                return VALORE*604800;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*2592000;
            case ANNI:
                RESTO=0;
                return VALORE*31536000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*31104000;
        }
    }
    uint_64_t MINUTI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=60000000000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=60000000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=60000;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=60;
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                RESTO=0;
                return VALORE;
            case ORE:
                RESTO=0;
                return VALORE*60;
            case GIORNI:
                RESTO=0;
                return VALORE*1440;
            case SETTIMANE:
                RESTO=0;
                return VALORE*10080;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*43200;
            case ANNI:
                RESTO=0;
                return VALORE*525600;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*518400;
        }
    }
    uint_64_t ORE(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                RESTO=0;
                return VALORE;
            case GIORNI:
                RESTO=0;
                return VALORE*60000000;
            case SETTIMANE:
                RESTO=0;
                return VALORE*60000000;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
        }
    }
    uint_64_t GIORNI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case GIORNI:
                RESTO=0;
                return VALORE;
            case SETTIMANE:
                RESTO=0;
                return VALORE*60000000;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
        }
    }
    uint_64_t SETTIMANE(){\1
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case GIORNI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SETTIMANE:
                RESTO=0;
                return VALORE;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
        }
    }
    uint_64_t MESI_COMMERCIALI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case GIORNI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SETTIMANE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MESI_COMMERCIALI:
                RESTO=0;
                return VALORE;
            case ANNI:
                RESTO=0;
                return VALORE*60000000;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*60000000;
        }
    }
    uint_64_t ANNI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case GIORNI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SETTIMANE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MESI_COMMERCIALI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ANNI:
                RESTO=0;
                return VALORE;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE*1000;
        }
    }
    uint_64_t ANNI_COMMERCIALI(){
        switch(UNITA){
            case NANOSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MICROSECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MILLISECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SECONDI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MINUTI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ORE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case GIORNI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case SETTIMANE:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case MESI_COMMERCIALI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ANNI:
                uint_64_t DIVISORE=1000
                RESTO=VALORE%DIVISORE;
                return VALORE/DIVISORE;
            case ANNI_COMMERCIALI:
                RESTO=0;
                return VALORE;
        }
    }
    void CONVERTI_IN(UNITA_DI_TEMPO UNITA){
        switch(UNITA){
            case NANOSECONDI:
                VALORE = NANOSECONDI();
            case MICROSECONDI:
                VALORE = MICROSECONDI();
            case MILLISECONDI:
                VALORE = MILLISECONDI();
            case SECONDI:
                VALORE = SECONDI();
            case MINUTI:
                VALORE = MINUTI();
            case ORE:
                VALORE = ORE();
            case GIORNI:
                VALORE = GIORNI();
            case SETTIMANE:
                VALORE = SETTIMANE();
            case MESI_COMMERCIALI:
                VALORE = MESI_COMMERCIALI();
            case ANNI:
                VALORE = ANNI();
            case ANNI_COMMERCIALI:
                VALORE = ANNI_COMMERCIALI();
        }
        this->UNITA=UNITA;
    }
    
    uint64_t RESTO(){
        uint64_t R=RESTO;
        RESTO=0;
        return R;
    }
}

void ASPETTA(uint_64_t TEMPO,UNITA_DI_TEMPO UNITA){
    TEMPO T(TEMPO,UNITA);
    delayMicroseconds(T.MICROSECONDI());
}

struct ORARIO{
protected:
    uint64_t NANOSECONDI;
    uint64_t MICROSECONDI;
    uint64_t MILLISECONDI;
    uint64_t SECONDI;
    uint64_t ORA;
    uint64_t MINUTI;
public:
    
void ORA(uint64_t ORA){this->ORA = ORA;}
    
void MINUTI(uint64_t MINUTI){
 TEMPO T(MINUTI,MINUTI);
 if(MINUTI>59){
    ORA += T.ORE();
    this->MINUTI += T.RESTO();
    }
}
else{this->MINUTI += MINUTI;}
}

void SECONDI(uint64_t SECONDI){
TEMPO T(SECONDI,SECONDI);
if(SECONDI > 59){
    MINUTI(T.MINUTI);
    SECONDI += T.RESTO();
}
else{SECONDI += T.VALORE;}
}

void MILLISECONDI(uint64_t MILLISECONDI){
TEMPO T(MILLISECONDI,MILLISECONDI);
if(MILLISECONDI > 999){
    SECONDI(T.SECONDI());
    MILLESECONDI += T.RESTO();
}
else{MILLISECONDI += T.VALORE;}
}

void MICROSECONDI(uint64_t MICROSECONDI){
TEMPO T(MICROSECONDI,MICROSECONDI);
if(MICROSECONDI > 999){
    MILLISECONDI(T.MILLISECONDI());
    MICROSECONDI += T.RESTO();
}
else{MICROSECONDI += T.VALORE;}
}
    
void NANOSECONDI(uint64_t NANOSECONDI){
TEMPO T(NANOSECONDI,NANOSECONDI);
if(NANOSECONDI > 999){
    MICROSECONDI(T.MICROSECONDI());
    NANOSECONDI += T.RESTO();
}
else{NANOSECONDI += T.VALORE;}
}
      
uint64_t  NANOSECONDI(){return NANOSECONDI;}
uint64_t  MICROSECONDI(){return MICROSECONDI;}
uint64_t  MILLISECONDI(){return MILLISECONDI;}
uint64_t  SECONDI(){return SECONDI;}
uint64_t  MINUTI(){return MINUTI;}
uint64_t  ORA(){return ORA;}
ORARIO(uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA){
ORA(ORA);
MINUTI(MINUTI);
SECONDI(SECONDI);
 }
ORARIO(uint64_t NANOSECONDI, MICROSECONDI,uint64_t MILLISECONDI,uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA){
ORA(ORA);
MINUTI(MINUTI);
SECONDI(SECONDI);
MILLISECONDI(MILLISECONDI);
MICROSECONDI(MICROSECONDI);
NANOSECONDI(NANOSECONDI);
 }
ORARIO(TEMPO TEMPO_DA_IMPOSTARE){
 ORA(TEMPO_DA_IMPOSTARE.ORA());
 MINUTI(TEMPO_DA_IMPOSTARE.MINUTI());
 SECONDI(TEMPO_DA_IMPOSTARE.SECONDI());
 MILLISECONDI(TEMPO_DA_IMPOSTARE.MILLISECONDI());
 MICROSECONDI(TEMPO_DA_IMPOSTARE.MICROSECONDI());
 NANOSECONDI(TEMPO_DA_IMPOSTARE.NANOSECONDI());
}
};

class DATA_F:ORARIO{
};

class CRONOMETRO{
protected:
boolean CRONOMETRO_ATTIVO;
TEMPO T0(0,MICROSECONDI);
TEMPO TEMPO_PASSATO;
UNITA_DI_TEMPO UNITA_DI_TEMPO_CRONOMETRO;
public:
void IMPOSTA_UNITA_DI_TEMPO(UNITA_DI_TEMPO UNITA_DI_TEMPO_CRONOMETRO){this->UNITA_DI_TEMPO_CRONOMETRO = UNITA_DI_TEMPO_CRONOMETRO;}
CRONOMETRO(UNITA_DI_TEMPO UNITA){IMPOSTA_UNITA_DI_TEMPO(UNITA);}
void AVVIA(){
CRONOMETRO_ATTIVO=1;
T0.VALORE = micros();
}
void STOPPA(){CRONOMETRO_ATTIVO=0;}
TEMPO TEMPO_PASSATO(){
if(CRONOMETRO_ATTIVO){
TEMPO_PASSATO = TEMPO(micros()-T0.VALORE,MICROSECONDI);
TEMPO_PASSATO.CONVERTI_IN(UNITA);
return TEMPO_PASSATO;
}
else{return 0;}
}
};

class OROLOGIO_VIRTUALE:CRONOMETRO{
ORARIO O;
OROLOGIO(uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA):CRONOMETRO(MICROSECONDI){
O=ORARIO(SECONDI,MINUTI,ORA);
 }
 OROLOGIO(uint64_t NANOSECONDI,uint64_t MICROSECONDI,uint64_t MILLISECONDI,uint64_t SECONDI,uint64_t MINUTI,uint64_t ORA):CRONOMETRO(MICROSECONDI){
O=ORARIO(NANOSECONDI,MICROSECONDI,MILLISECONDI,SECONDI,MINUTI,ORA);
 }
void FUNZIONE(){
O = ORARIO(TEMPO_PASSATO());
}
};

enum TIPO_TIMER{NON_BLOCCANTE,BLOCCANTE}
class TIMER:CRONOMETRO{
protected:
  TEMPO PERIODO;
  TIPO_TIMER T_TIMER;
public:
boolean ABILITATO;
void ABILITA(){
    switch(T_TIMER){
        case NON_BLOCCANTE:
            AVVIA();
            ABILITATO=1;
            break;
    }
}
void DISABILITA(){STOPPA(); ABILITATO=0;}
TEMPO TEMPO_PASSATO_FINO_AD_ORA(){return TEMPO_PASSATO();}
void IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(uint_64_t PERIODO,UNITA_DI_TEMPO UNITA){
IMPOSTA_UNITA_DI_TEMPO(UNITA);
PERIODO = TEMPO(PERIODO,UNITA);
PERIODO.CONVERTI_IN(MICROSECONDI);
}
void IMPOSTA_TIPO_TIMER(TIPO_TIMER TIPO){ this->TIPO=TIPO;}
boolean STOP(){
    switch(T_TIMER){
        case NON_BLOCCANTE:
            if(TEMPO_PASSATO()>=PERIODO.VALORE){DISABILITA(); return 1;}
            return 0;
        case BLOCCANTE:
            ASPETTA(PERIODO.VALORE,PERIODO.UNITA);
            return 1;
    }
}
TIMER():CRONOMETRO(MICROSECONDI){}
TIMER(uint_64_t PERIODO,UNITA_DI_TEMPO UNITA):CRONOMETRO(UNITA){IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(PERIODO,UNITA);}
TIMER(uint_64_t PERIODO,UNITA_DI_TEMPO UNITA, TIPO_TIMER TIPO):CRONOMETRO(UNITA){
    IMPOSTA_PERIODO_E_UNITA_DI_TEMPO(PERIODO,UNITA);
    IMPOSTA_TIPO_TIMER(TIPO);
}
};

class CICLO_TIMER:TIMER{
public:
  boolean INIZIALIZZATO;
  CICLO_TIMER(uint_64_t PERIODO,UNITA_DI_TEMPO UNITA):TIMER(PERIODO,UNITA){INIZIALIZZATO=1;}
  CICLO_TIMER(uint_64_t PERIODO,UNITA_DI_TEMPO UNITA,TIPO_TIMER TIPO):TIMER(PERIODO,UNITA,TIPO){INIZIALIZZATO=1;}
  CICLO_TIMER():TIMER(0,MICROSECONDI){}
boolean TICK(){
if(!ABILITATO){ABILITA();}
if(STOP()){ABILITA(); return 1;}
return 0;
}
};

enum MODALITA_RESISTENZA{RESISTENZA_ESTERNA,PULLUP,PULLDOWN}
enum MODALITA_LETTURA_DIGITALE{NORMALE,INVERTITA};
class ENTRATA{
protected:
    uint8_t PIN;
    MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE;
public:
    void RESISTENZA_ESTERNA(){M_RESISTENZA=RESISTENZA_ESTERNA; pinMode(PIN,INPUT);}
    void PULLUP(){M_RESISTENZA=PULLUP; pinMode(PIN,INPUT_PULLUP);}
    void PULLDOWN(){M_RESISTENZA=PULLDOWN; digitalWrite(PIN,0);}
protected:
    void IMPOSTA_PIN(uint8_t PIN){this->PIN=PIN; RESISTENZA_ESTERNA();}
    void IMPOSTA_MODALITA_RESISTENZA(MODALITA_RESISTENZA M_RESISTENZA){
     switch(M_RESISTENZA){
        case RESISTENZA_ESTERNA:
            RESISTENZA_ESTERNA();
            break;
        case PULLUP:
            PULLUP();
            break;
        case PULLDOWN:
            PULLDOWN();
            break;
           }
    }
    void IMPOSTA_MODALITA_LETTURA_DIGITALE(MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE){
        this->M_LETTURA_DIGITALE=M_LETTURA_DIGITALE;
    }
public:
    ENTRATA(){}
    ENTRATA(uint8_t PIN){IMPOSTA_PIN(PIN);}
    ENTRATA(uint8_t PIN,MODALITA_RESISTENZA M_RESISTENZA){
     IMPOSTA_MODALITA_RESISTENZA(M_RESISTENZA);
     IMPOSTA_PIN(PIN);
    }
    ENTRATA(uint8_t PIN,MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE){
     IMPOSTA_MODALITA_LETTURA_DIGITALE(M_LETTURA_DIGITALE);
     IMPOSTA_PIN(PIN);
    }
    ENTRATA(uint8_t PIN,MODALITA_RESISTENZA M_RESISTENZA,MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE){
     IMPOSTA_MODALITA_RESISTENZA(M_RESISTENZA);
     IMPOSTA_MODALITA_LETTURA_DIGITALE(M_LETTURA_DIGITALE);
     IMPOSTA_PIN(PIN);
    }
    boolean LETTURA_DIGITALE(){
    boolean L=digitalRead(PIN);
    switch(MODALITA_LETTURA_DIGITALE){
        case NORMALE:
            return L;
            break;
        case INVERTITA:
            return !L;
            break;
        }
    }
    uint16_t LETTURA_ANALOGICA(){return analogRead(PIN);}
};

enum MEMORIZZA_STATO:boolean{NON_SALVARE_LO_STATO=0,SALVA_STATO=1};
enum TIPO_USCITA_DIGITALE{NORMALE,INVERTITA}
class USCITA{
protected:
    uint8_t PIN;
    CICLO_TIMER LAMPEGGIO;
    TIMER PERIODO;
    TIPO_USCITA_DIGITALE TIPO_D;
    MEMORIZZA_STATO SALVA;
    void IMPOSTA_PIN(uint8_t PIN){this->PIN=PIN; pinMode(PIN,OUTPUT);}
public:
    void IMPOSTA_STATO(uint8_t PERCENTUALE){
     if(PERCENTUALE==100){
        switch(TIPO_D){
            case NORMALE:
                digitalWrite(PIN,1);
                break;
            case INVERTITA:
                digitalWrite(PIN,0);
                break;
            }
        }
    else{analogWrite(PIN,(PERCENTUALE*255)/100);}
    if(SALVA){EEPROM.update(PIN,PERCENTUALE);}
    }
    void IMPOSTA_STATO_ANALOGICO(uint8_t STATO){IMPOSTA_STATO((STATO*100)/255);}
    USCITA(){}
    USCITA(uint8_t PIN){IMPOSTA_PIN(PIN);}
    USCITA(uint8_t PIN,TIPO_USCITA TIPO){
     this->TIPO=TIPO;
     IMPOSTA_PIN(PIN);
    }
    USCITA(uint8_t PIN,ENUM_SALVA_STATO SALVA){
     this->SALVA=SALVA;
     IMPOSTA_PIN(PIN);
     IMPOSTA_STATO(EEPROM.read(PIN));
    }
    USCITA(uint8_t PIN,TIPO_USCITA_DIGITALE TIPO_D,ENUM_SALVA_STATO SALVA){
     this->TIPO_D=TIPO_D;
     this->SALVA=SALVA;
     IMPOSTA_PIN(PIN);
     IMPOSTA_STATO(EEPROM.read(PIN));
    }
    void ACCENDI(){IMPOSTA_STATO(100);}
    void SPEGNI(){IMPOSTA_STATO(0);}
    void IMPOSTA_STATO_IN_RITARDO(uint8_t PERCENTUALE,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA){
        ASPETTA(RITARDO,UNITA);
        IMPOSTA_STATO(PERCENTUALE);
    }
    void IMPOSTA_STATO_IN_RITARDO_CON_TIMER(uint8_t PERCENTUALE,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA){
        if(RITARDO.ABILITATO == 0){RITARDO=TIMER(RITARDO,UNITA);}
        if(RITARDO.STOP()){IMPOSTA_STATO(PERCENTUALE);}
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
     if(!LAMPEGGIO.INIZIALIZZATO){LAMPEGGIO = CICLO_TIMER(PERIODO,UNITA);}
     if(LAMPEGGIO.TICK()){INVERTI_STATO();}
    }
    void PULSAZIONE(uint8_t PERCENTUALE_MASSIMA,uint16_t PERIODO,UNITA_DI_TEMPO UNITA){
     ACCENDI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA);
     SPEGNI_CON_DISSOLVENZA(PERCENTUALE_MASSIMA);
    }
};

class LED:public USCITA {
public:
    LED(){}
    LED(uint8_t PIN):USCITA(PIN){}
    LED(uint8_t PIN,TIPO_USCITA TIPO):USCITA(PIN,TIPO_USCITA TIPO){}
    LED(uint8_t PIN,ENUM_SALVA_STATO SALVA):USCITA(PIN,SALVA){}
    LED(uint8_t PIN,TIPO_USCITA TIPO,ENUM_SALVA_STATO SALVA):USCITA(PIN,TIPO,SALVA){}
};

struct VALORI_RGB{
    uint8_t VERDE,ROSSO,BLU;
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
}
}
enum COLORI:VALORI_RGB{
    VERDE=VALORI_RGB(0,128,0),
    ROSSO=VALORI_RGB(255,0,0),
    BLU=VALORI_RGB(0,0,255),
    BIANCO=VALORI_RGB(255,255,255)
}
class LED_RGB{
public:
    LED VERDE(),ROSSO(),BLU();
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
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU,ENUM_SALVA_STATO SALVA){
     VERDE = LED(PIN_VERDE,SALVA);
     ROSSO = LED(PIN_ROSSO,SALVA);
     BLU = LED(PIN_BLU,SALVA);
    }
    LED_RGB(uint8_t PIN_VERDE,uint8_t PIN_ROSSO,uint8_t PIN_BLU,ENUM_SALVA_STATO SALVA,VALORI_RGB COLORE){
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

enum TIPO_RELE:TIPO_USCITA{NORMALE=TIPO_USCITA::NORMALE,LOGICA_INVERSA=INVERTITA};
class RELE:USCITA{
 public:
  RELE(uint8_t PIN,TIPO_RELE TIPO):USCITA(PIN,TIPO){}
  RELE(uint8_t PIN,TIPO_RELE TIPO,ENUM_SALVA_STATO SALVA_STATO):USCITA(PIN,TIPO,SALVA_STATO){}
  void ACCESO(){ACCENDI();}
  void SPENTO(){SPEGNI();}
  void INVERTI_STATO(){USCITA::INVERTI_STATO();}
  void LAMPEGGIO(){USCITA::LAMPEGGIO();}
};

enum TIPO_TERMOSTATO{
  RISCALDAMENTO,RAFFREDDAMENTO
};
class TERMOSTATO:RELE {
  protected:
   TIPO_TERMOSTATO TIPO_T;
  public:
  uint8_t SOGLIA_TEMPERATURA=20;
TERMOSTATO(uint8_t PIN_R,TIPO_RELE TIPORELE,TIPO_TERMOSTATO TIPO_T):RELE(PIN_R,TIPORELE,""){this->TIPO_T=TIPO_T;}
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
    PULSANTE(uint8_t PIN,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA):ENTRATA(PIN),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA,MODALITA_RESISTENZA M_RESISTENZA):ENTRATA(PIN,M_RESISTENZA),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA,MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE):ENTRATA(PIN,M_LETTURA_DIGITALE),CICLO_TIMER(RITARDO,UNITA){}
    PULSANTE(uint8_t PIN,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA,MODALITA_RESISTENZA M_RESISTENZA,
    MODALITA_LETTURA_DIGITALE M_LETTURA_DIGITALE):ENTRATA(PIN,M_RESISTENZA,M_LETTURA_DIGITALE),CICLO_TIMER(RITARDO,UNITA){}
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
  void RESISTENZA_ESTERNA() override {ENTRATA::RESISTENZA_ESTERNA();}
  void PULLUP() override {ENTRATA::PULLUP()}
  void PULLDOWN() override {ENTRATA::PULLDOWN()}
};

class FOTORESISTORE:ENTRATA,CICLO_TIMER {
protected:
uint16_t SOGLIA_ACCENSIONE;
uint16_t SOGLIA_SPEGNIMENTO;
boolean ULTIMO_CONTROLLO_ESEGUITO;
public:
FOTORESISTORE(uint8_t PIN,uint16_t SOGLIA_ACCENSIONE,uint16_t SOGLIA_SPEGNIMENTO,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA):ENTRATA(PIN),CICLO_TIMER(RITARDO,UNITA){
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
CREPUSCOLARE(uint8_t PIN_FOTORESISTORE,uint16_t SOGLIA_ACCENSIONE,uint16_t SOGLIA_SPEGNIMENTO,uint_64_t RITARDO,UNITA_DI_TEMPO UNITA,
uint8_t PIN_RELE,TIPO_RELE TIPORELE):FOTORESISTORE(PIN_FOTORESISTORE,SOGLIA_ACCENSIONE,SOGLIA_SPEGNIMENTO,RITARDO,UNITA),
RELE(PIN_RELE,TIPORELE,"ESTERNO"){}
void FUNZIONE_CREPUSCOLARE(){
  if(CONTROLLO()){ACCESO();}
  else{SPENTO();}
}
};

class BLUETOOTH {
public:
String RISULTATO_ASCOLTO;
BLUETOOTH(int baud_rate){Serial.begin(baud_rate);}
void ASCOLTO(){
  if(Serial.available()){
    RISULTATO_ASCOLTO = Serial.readString();
  }
}
void INVIO(String V){
Serial.print(V);
}
};

class INGRESSO_MONITORATO{
 public:
   uint16_t FINECORSA_APERTURA;
   uint16_t FINECORSA_CHIUSURA;
   virtual boolean APERTO();
   virtual boolean CHIUSO();
};

class INGRESSO_FISICO:INGRESSO_MONITORATO{
 protected:
  PULSANTE PULSANTE_FINECORSA_APERTURA;
  PULSANTE PULSANTE_FINECORSA_CHIUSURA;
 public:
  INGRESSO_FISICO(uint8_t PIN_FINECORSA_APERTURA,uint8_t PIN_FINECORSA_CHIUSURA,uint_64_t RITARDO_FINECORSA1,UNITA_DI_TEMPO UNITA_FINECORSA1,
  uint_64_t RITARDO_FINECORSA2,UNITA_DI_TEMPO UNITA_FINECORSA2){
  PULSANTE_FINECORSA_APERTURA = PULSANTE(PIN_FINECORSA_APERTURA,RITARDO_FINECORSA1,UNITA_FINECORSA1);
  PULSANTE_FINECORSA_CHIUSURA = PULSANTE(PIN_FINECORSA_CHIUSURA,RITARDO_FINECORSA2,UNITA_FINECORSA2);
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
  virtual APRI();
  virtual CHIUDI();
  void CONTROLLO_STATO_MOVIMENTO(){
    STATO_DEL_MOVIMENTO STATO;
    EEPROM.get(INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO,STATO);
    switch(STATO){
        case CHIUSURA:
            CHIUDI();
        case APERTURA:
            APRI();
        }
    }
};

class INGRESSO_MOTORIZZATO:public INGRESSO_MONITORATO,public STATO_MOVIMENTO{};

class MOTORE_SWIPING{
public:
    CICLO_TIMER CICLO;
    virtual uint16_t POSIZIONE_CORRENTE();
    virtual SWIPE_AVANTI();
    virtual SWIPE_INDIETRO();
    void SWIPING(uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
     if(CICLO.INIZIALIZZATO == 0){CICLO = CICLO_TIMER(TEMPO_DA_FERMO,UNITA);}
    if(CICLO.TICK() && CICLO.INIZIALIZZATO){
     if(POSIZIONE_CORRENTE() == GRADI_GIU) {AVANTI();}
     else if(POSIZIONE_CORRENTE() == GRADI_SU){INDIETRO();}
     }
    }
};

class SERVOMOTORE:Servo,MOTORE_SWIPING{
 protected:
    uint8_t PIN;
    byte INDIRIZZO_EEPROM_GRADI;
    byte GRADI_AVANTI;
    byte GRADI_INDIETRO;
    uint16_t PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI;
  void SCRIVI_POSIZIONE(byte GRADI){
    write(GRADI);
    EEPROM.put(INDIRIZZO_EEPROM_GRADI,GRADI);
  }
  void AUMENTA_POSIZIONE(byte GRADI,uint16_t PERIODO_IN_MILLISECONDI){
   for(uint16_t P=POSIZIONE_CORRENTE();P<GRADI;P++){
    SCRIVI_POSIZIONE(P);
    delay(PERIODO_IN_MILLISECONDI);
    }
  }
  void DIMINUISCI_POSIZIONE(byte GRADI,uint16_t PERIODO_IN_MILLISECONDI){
    for(uint16_t P=POSIZIONE_CORRENTE();P>GRADI;P--){
    SCRIVI_POSIZIONE(P);
    delay(PERIODO_IN_MILLISECONDI);
    }
  }
  void ATTACCA(){
   attach(PIN);
   write(POSIZIONE_CORRENTE());
   }
  void SWIPE_AVANTI() override {
    IMPOSTA_POSIZIONE(GRADI_AVANTI, PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI);
    }
  void SWIPE_INDIETRO() override {
    IMPOSTA_POSIZIONE(GRADI_INDIETRO, PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI);
    }
 public:
  byte POSIZIONE_CORRENTE(){return EEPROM.read(INDIRIZZO_EEPROM_GRADI);}
  SERVOMOTORE(uint8_t PIN):Servo(){
  this->INDIRIZZO_EEPROM_GRADI=PIN;
  this->PIN = PIN;
  /*NON SI PUO USARE LA FUNZIONE "attach" PRIMA DEL SETUP,
  IPOTIZZO CHE PRIMA DEL SETUP NON VENGONO INIZIALIZZATE LE FUNZIONI PRINCIPALI DELL'AMBIENTE DI SVILUPPO,
  QUINDI VERRA ESEGUITO LA PRIMA VOLTA CHE SI IMPOSTA LA POSIZIONE*/
  }
  void IMPOSTA_POSIZIONE(uint16_t GRADI,uint16_t PERIODO_IN_MILLISECONDI){
    if(attached()==0){ATTACCA();}
    if(PERIODO_IN_MILLISECONDI>0){
    AUMENTA_POSIZIONE(GRADI,PERIODO_IN_MILLISECONDI);
    DIMINUISCI_POSIZIONE(GRADI,PERIODO_IN_MILLISECONDI);
   }
   else{SCRIVI_POSIZIONE(GRADI);}
  }
    void SWIPING(byte GRADI_AVANTI, byte GRADI_INDIETRO, uint16_t PERIODO_SPOSTAMENTO_IN_MILLISECONDI,uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
        this->GRADI_AVANTI = GRADI_AVANTI;
        this->GRADI_INDIETRO = GRADI_INDIETRO;
        PERIODO_SPOSTAMENTO_SWIPING_IN_MILLISECONDI = PERIODO_SPOSTAMENTO_IN_MILLISECONDI;
        SWIPING(TEMPO_DA_FERMO,UNITA);
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
   SERVO_INGRESSO(uint8_t PIN,uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO,uint16_t POSIZIONE_APERTURA,uint16_t POSIZIONE_CHIUSURA,
   uint16_t RITARDO_MOVIMENTO_IN_MILLISECONDI):SERVOMOTORE(PIN){
   this->RITARDO_MOVIMENTO_IN_MILLISECONDI = RITARDO_MOVIMENTO_IN_MILLISECONDI;
   INGRESSO_MOTORIZZATO::INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO = INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO;
   FINECORSA_APERTURA = POSIZIONE_APERTURA;
   FINECORSA_CHIUSURA = POSIZIONE_CHIUSURA;
   CONTROLLO_STATO_MOVIMENTO();
   }
   
};

class MOTORE_STEPPER_BASE:MOTORE_SWIPING{
protected:
 uint16_t PASSI_MASSIMI;
 uint16_t INDIRIZZO_POSIZIONE_EEPROM;
 uint8_t VELOCITA;
 void MEMORIZZA_PASSI(uint16_t PASSI){EEPROM.put(INDIRIZZO_POSIZIONE_EEPROM,PASSI);}
public:
  void IMPOSTA_VELOCITA(uint8_t VELOCITA){this->VELOCITA=VELOCITA;}
  MOTORE_STEPPER_BASE(uint16_t STEP_MASSIMI,uint8_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_EEPROM){
  this->STEP_MASSIMI=STEP_MASSIMI;
  this->INDIRIZZO_POSIZIONE_EEPROM = INDIRIZZO_POSIZIONE_EEPROM;
  IMPOSTA_VELOCITA(VELOCITA);
  }
  uint16_t POSIZIONE_CORRENTE(){
     uint16_t R;
     EEPROM.get(INDIRIZZO_POSIZIONE_EEPROM,R);
     return R;
    }
  virtual void PASSO();
  virtual void SINISTRA();
  virtual void DESTRA();
  void PASSI(uint16_t PASSI){for(uint16_t P; P<PASSI; P++){PASSO();} MEMORIZZA_PASSI(PASSI);}
protected:
  uint16_t PASSI_AVANTI;
  uint16_t PASSI_INDIETRO;
  void SWIPE_AVANTI() override {PASSI(PASSI_AVANTI);}
  void SWIPE_INDIETRO() override {PASSI(PASSI_INDIETRO);}
public:
  void SWIPING(uint16_t PASSI_AVANTI,uint16_t PASSI_INDIETRO,uint16_t TEMPO_DA_FERMO, UNITA_DI_TEMPO UNITA){
      this->PASSI_AVANTI = PASSI_AVANTI;
      this->PASSI_INDIETRO = PASSI_INDIETRO;
      SWIPING(TEMPO_DA_FERMO,UNITA);
  }
};

class MOTORE_STEPPER: public MOTORE_STEPPER_BASE{
private:
    uint8_t PIN_CONTROLLO_PASSO;
    uint8_t PIN_VERSO;
    boolean STATO_PIN_VERSO_DESTRA;
public:
    MOTORE_STEPPER(uint8_t PIN_CONTROLLO_PASSO,uint8_t PIN_VERSO, boolean STATO_PIN_VERSO_DESTRA, uint16_t PASSI_MASSIMI,uint16_t INDIRIZZO_POSIZIONE_EEPROM,uint8_t VELOCITA):
    MOTORE_STEPPER_BASE(PASSI_MASSIMI,VELOCITA,INDIRIZZO_POSIZIONE_EEPROM){
     this->PIN_CONTROLLO_PASSO=PIN_CONTROLLO_PASSO;
     this->PIN_VERSO=PIN_VERSO;
     pinMode(PIN_CONTROLLO_PASSO,OUTPUT);
     pinMode(PIN_VERSO,OUTPUT);
     }
    void PASSO() override {
        digitalWrite(PIN_CONTROLLO_PASSO,HIGH);
        delay(10);
        digitalWrite(PIN_CONTROLLO_PASSO,LOW);
     }
    void DESTRA() override {digitalWrite(PIN_VERSO,STATO_PIN_VERSO_DESTRA);}
    void SINISTRA() override {digitalWrite(PIN_VERSO,!STATO_PIN_VERSO_DESTRA);}
};

class MOTORE_STEPPER_4_BOBINE:Stepper,public MOTORE_STEPPER_BASE{
  public:
    void IMPOSTA_VELOCITA(uint16_t VELOCITA) override {
    MOTORE_STEPPER_BASE:IMPOSTA_VELOCITA(VELOCITA);
    setSpeed(VELOCITA);
  }
    MOTORE_STEPPER_4_BOBINE(uint16_t PASSI_MASSIMI,uint8_t PIN_BOBINA1,uint8_t PIN_BOBINA2,uint8_t PIN_BOBINA3,uint8_t PIN_BOBINA4,uint16_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_EEPROM):
     MOTORE_STEPPER_BASE(PASSI_MASSIMI,VELOCITA,INDIRIZZO_POSIZIONE_EEPROM),
     Stepper(PASSI_MASSIMI,PIN_BOBINA1,PIN_BOBINA2,PIN_BOBINA3,PIN_BOBINA4){
     IMPOSTA_VELOCITA(VELOCITA);
  }
    void PASSO() override{step(1);}
};

class STEPPER_INGRESSO_BASE: public INGRESSO_MOTORIZZATO {
    virtual uint16_t POSIZIONE_CORRENTE();
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
}

class STEPPER_INGRESSO:MOTORE_STEPPER,public STEPPER_INGRESSO_BASE{
public:
    uint16_t POSIZIONE_CORRENTE() override {return MOTORE_STEPPER:POSIZIONE_CORRENTE();}
    STEPPER_INGRESSO(uint8_t PIN_CONTROLLO_PASSO,uint8_t PIN_VERSO, boolean STATO_PIN_VERSO_DESTRA, uint16_t PASSI_MASSIMI,uint16_t INDIRIZZO_POSIZIONE_EEPROM,uint8_t VELOCITA,
    uint16_t PASSI_APERTURA,uint16_t PASSI_CHIUSURA,uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO):
    MOTORE_STEPPER(PIN_CONTROLLO_PASSO,PIN_VERSO,STATO_PIN_VERSO_DESTRA,PASSI_MASSIMI,INDIRIZZO_POSIZIONE_EEPROM,VELOCITA){
     IMPOSTA_VELOCITA(VELOCITA);
     FINECORSA_APERTURA = PASSI_APERTURA;
     FINECORSA_CHIUSURA = PASSI_CHIUSURA;
     INGRESSO_MOTORIZZATO::INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO = INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO;
     CONTROLLO_STATO_MOVIMENTO();
     }
};

class STEPPER_INGRESSO_4_BOBINE:MOTORE_STEPPER_4_BOBINE,public STEPPER_INGRESSO_BASE{
  public:
    uint16_t POSIZIONE_CORRENTE() override {return MOTORE_STEPPER_4_BOBINE:POSIZIONE_CORRENTE();}
    STEPPER_INGRESSO(uint16_t PASSI_MASSIMI,uint8_t PIN_BOBINA1,uint8_t PIN_BOBINA2,uint8_t PIN_BOBINA3,uint8_t PIN_BOBINA4,
    uint16_t INDIRIZZO_POSIZIONE_EEPROM,uint16_t PASSI_APERTURA,uint16_t PASSI_CHIUSURA,uint8_t VELOCITA,uint16_t INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO):
    MOTORE_STEPPER_4_BOBINE(PASSI_MASSIMI,VELOCITA,PIN_BOBINA1,PIN_BOBINA2,PIN_BOBINA3,PIN_BOBINA4){
     FINECORSA_APERTURA = PASSI_APERTURA;
     FINECORSA_CHIUSURA = PASSI_CHIUSURA;
     INGRESSO_MOTORIZZATO::INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO = INDIRIZZO_POSIZIONE_STATO_DEL_MOVIMENTO;
     CONTROLLO_STATO_MOVIMENTO();
     }
};

class TASTIERA_A_MATRICE{
    
};

class ALLARME:TASTIERA_A_MATRICE{
    
};

#endif
