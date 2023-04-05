#ifndef EepromNumFraschetta_h
#define EepromNumFraschetta_h
#include "NumSplitJoinFraschetta.h"
#include "EEPROM.h"
namespace EepromNumF{
    struct EepromUint16T{
     protected:
        uint16_t Cell0,Cell1;
        void SetCells(uint16_t Cell0,uint16_t Cell1){
         this->Cell0=Cell0; this->Cell1=Cell1;
        }
     public:
        void Value(uint16_t N){
         uint8_t A[2];
         NumSplitJoinF::SplitIntoTwoUint16T(N,A);
         EEPROM.update(Cell0,A[0]); EEPROM.update(Cell1,A[1]);
        }
        uint16_t Value(){return NumSplitJoinF::JoinUint16T(EEPROM.read(Cell0),EEPROM.read(Cell1));}
        EepromUint16T(uint16_t Cell0,uint16_t Cell1){SetCells(Cell0,Cell1);}
        EepromUint16T(uint16_t Cell0,uint16_t Cell1, uint8_t Value){
         SetCells(Cell0,Cell1); this->Value(Value);
        }
        EepromUint16T(){}
    };
    
    struct EepromUint32T{
      protected:
        uint16_t Cell0,Cell1,Cell2,Cell3;
        void SetCells(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3){
         this->Cell0=Cell0; this->Cell1=Cell1;
         this->Cell2=Cell2; this->Cell3=Cell3;
        }
      public:
        void Value(uint32_t N){
         uint8_t A[4];
         NumSplitJoinF::SplitIntoFourUint32T(N,A);
         EEPROM.update(Cell0,A[0]); EEPROM.update(Cell1,A[1]);
         EEPROM.update(Cell2,A[2]); EEPROM.update(Cell3,A[3]);
        }
        uint32_t Value(){return NumSplitJoinF::JoinUint32T(EEPROM.read(Cell0),EEPROM.read(Cell1),EEPROM.read(Cell2),EEPROM.read(Cell3));}
        EepromUint32T(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3){
         SetCells(Cell0,Cell1,Cell2,Cell3);
        }
        EepromUint32T(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3,uint32_t Value){
         SetCells(Cell0,Cell1,Cell2,Cell3);
         this->Value(Value);
        }
        EepromUint32T(){}
    };
    
    struct EepromUint64T{
     protected:
      uint16_t Cell0,Cell1,Cell2,Cell3,Cell4,Cell5,Cell6,Cell7;
      void SetCells(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3,uint16_t Cell4,uint16_t Cell5,uint16_t Cell6,uint16_t Cell7){
          this->Cell0=Cell0; this->Cell1=Cell1;
          this->Cell2=Cell2; this->Cell3=Cell3;
          this->Cell4=Cell4; this->Cell5=Cell5;
          this->Cell6=Cell6; this->Cell7=Cell7;
      }
        void Value(uint64_t N){
         uint8_t A[8];
         NumSplitJoinF::SplitIntoEightUint64T(N,A);
         EEPROM.update(Cell0,A[0]); EEPROM.update(Cell1,A[1]);
         EEPROM.update(Cell2,A[2]); EEPROM.update(Cell3,A[3]);
         EEPROM.update(Cell4,A[4]); EEPROM.update(Cell5,A[5]);
         EEPROM.update(Cell6,A[6]); EEPROM.update(Cell7,A[7]);
        }
        void Value(){
         return NumSplitJoinF::JoinUint64T(EEPROM.read(Cell0),EEPROM.read(Cell1),EEPROM.read(Cell2),EEPROM.read(Cell3),
         EEPROM.read(Cell4),EEPROM.read(Cell5),EEPROM.read(Cell6),EEPROM.read(Cell7));
        }
        EepromUint64T(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3,uint16_t Cell4,uint16_t Cell5,uint16_t Cell6,uint16_t Cell7){
         SetCells(Cell0,Cell1,Cell2,Cell3,Cell4,Cell5,Cell6,Cell7);
        }
        EepromUint64T(uint16_t Cell0,uint16_t Cell1,uint16_t Cell2,uint16_t Cell3,uint16_t Cell4,uint16_t Cell5,uint16_t Cell6,uint16_t Cell7, uint64_t Value){
         SetCells(Cell0,Cell1,Cell2,Cell3,Cell4,Cell5,Cell6,Cell7);
         this->Value(Value);
        }
        EepromUint64T(){}
    };
};
#endif
