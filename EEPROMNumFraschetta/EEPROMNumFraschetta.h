#ifndef EEPROMNumFraschetta_h
#define EEPROMNumFraschetta_h
#include <NumSplitJoinFraschetta.h>
namespace NE{ //NUMERI EEPROM
    struct EEPROM_UINT16_T{
     protected:
        uint16_t CELLA0,CELLA1;
        void IMPOSTA_CELLE(uint16_t &CELLA0,uint16_t &CELLA1){
         this->CELLA0=CELLA0; this->CELLA1=CELLA1;
        }
     public:
        void VALORE(uint16_t N){
         uint8_t A[2];
         DUN::DIVIDI_IN_DUE_UINT16_T(N,A);
         EEPROM.update(CELLA0,A[0]); EEPROM.update(CELLA1,A[1]);
        }
        uint16_t VALORE(){return DUN::UNISCI_UINT16_T(EEPROM.read(CELLA0),EEPROM.read(CELLA1));}
        EEPROM_UINT16_T(uint16_t CELLA0,uint16_t CELLA1){
         IMPOSTA_CELLE(CELLA0,CELLA1);
        }
        EEPROM_UINT16_T(uint16_t CELLA0,uint16_t CELLA1, uint8_t VALORE){
         IMPOSTA_CELLE(CELLA0,CELLA1);
         this->VALORE(VALORE);
        }
        EEPROM_UINT16_T(){}
    };
    
    struct EEPROM_UINT32_T{
      protected:
        uint16_t CELLA0,CELLA1,CELLA2,CELLA3;
        void IMPOSTA_CELLE(uint16_t &CELLA0,uint16_t &CELLA1,uint16_t &CELLA2,uint16_t &CELLA3){
         this->CELLA0=CELLA0; this->CELLA1=CELLA1;
         this->CELLA2=CELLA2; this->CELLA3=CELLA3;
        }
      public:
        void VALORE(uint32_t N){
         uint8_t A[4];
         DUN::DIVIDI_IN_QUATTRO_UINT32_T(N,A);
         EEPROM.update(CELLA0,A[0]); EEPROM.update(CELLA1,A[1]);
         EEPROM.update(CELLA2,A[2]); EEPROM.update(CELLA3,A[3]);
        }
        uint32_t VALORE(){return DUN::UNISCI_UINT32_T(EEPROM.read(CELLA0),EEPROM.read(CELLA1),EEPROM.read(CELLA2),EEPROM.read(CELLA3));}
        EEPROM_UINT32_T(uint16_t CELLA0,uint16_t CELLA1,uint16_t CELLA2,uint16_t CELLA3){
         IMPOSTA_CELLE(CELLA0,CELLA1,CELLA2,CELLA3);
        }
        EEPROM_UINT32_T(uint16_t CELLA0,uint16_t CELLA1,uint16_t CELLA2,uint16_t CELLA3,uint32_t VALORE){
         IMPOSTA_CELLE(CELLA0,CELLA1,CELLA2,CELLA3);
         this->VALORE(VALORE);
        }
        EEPROM_UINT32_T(){}
    };
    
    struct EEPROM_UINT64_T{
     protected:
      uint16_t CELLA0,CELLA1,CELLA2,CELLA3,CELLA4,CELLA5,CELLA6,CELLA7;
      void IMPOSTA_CELLE(uint16_t &CELLA0,uint16_t &CELLA1,uint16_t &CELLA2,uint16_t &CELLA3,uint16_t &CELLA4,uint16_t &CELLA5,uint16_t &CELLA6,uint16_t &CELLA7){
          this->CELLA0=CELLA0; this->CELLA1=CELLA1;
          this->CELLA2=CELLA2; this->CELLA3=CELLA3;
          this->CELLA4=CELLA4; this->CELLA5=CELLA5;
          this->CELLA6=CELLA6; this->CELLA7=CELLA7;
      }
        void VALORE(uint64_t N){
         uint8_t A[8];
         DUN::DIVIDI_IN_OTTO_UINT64_T(N,A);
         EEPROM.update(CELLA0,A[0]); EEPROM.update(CELLA1,A[1]);
         EEPROM.update(CELLA2,A[2]); EEPROM.update(CELLA3,A[3]);
         EEPROM.update(CELLA4,A[4]); EEPROM.update(CELLA5,A[5]);
         EEPROM.update(CELLA6,A[6]); EEPROM.update(CELLA7,A[7]);
        }
        void VALORE(){
         return DUN::UNISCI_UINT64_T(EEPROM.read(CELLA0),EEPROM.read(CELLA1),EEPROM.read(CELLA2),EEPROM.read(CELLA3),
         EEPROM.read(CELLA4),EEPROM.read(CELLA5),EEPROM.read(CELLA6),EEPROM.read(CELLA7));
        }
        EEPROM_UINT64_T(uint16_t CELLA0,uint16_t CELLA1,uint16_t CELLA2,uint16_t CELLA3,uint16_t CELLA4,uint16_t CELLA5,uint16_t CELLA6,uint16_t CELLA7){
         IMPOSTA_CELLE(CELLA0,CELLA1,CELLA2,CELLA3,CELLA4,CELLA5,CELLA6,CELLA7);
        }
        EEPROM_UINT64_T(uint16_t CELLA0,uint16_t CELLA1,uint16_t CELLA2,uint16_t CELLA3,uint16_t CELLA4,uint16_t CELLA5,uint16_t CELLA6,uint16_t CELLA7, uint64_t VALORE){
         IMPOSTA_CELLE(CELLA0,CELLA1,CELLA2,CELLA3,CELLA4,CELLA5,CELLA6,CELLA7);
         this->VALORE(VALORE);
        }
        EEPROM_UINT64_T(){}
    };
};
#endif
