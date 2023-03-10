#ifndef NumSplitJoinFraschetta_h
#define NumSplitJoinFraschetta_h
#include <NumByteFraschetta.h>
namespace DUN{ //DIVIDI UNISCI NUMERI
    uint8_t DIVIDI_IN_DUE_UINT16_T(uint16_t N, uint8_t A[2]){
        A[0]=LSBDN::LEGGI_BYTE(0,N); A[1]=LSBDN::LEGGI_BYTE(1,N);
    }
    uint16_t UNISCI_UINT16_T(uint8_t B_0,uint8_t B_1){
        uint16_t N;
        LSBDN::SCRIVI_BYTE(0,N,B_0); LSBDN::SCRIVI_BYTE(1,N,B_1);
        return N;
    }
    uint8_t DIVIDI_IN_QUATTRO_UINT32_T(uint32_t N, uint8_t A[4]){
        A[0]=LSBDN::LEGGI_BYTE(0,N); A[1]=LSBDN::LEGGI_BYTE(1,N);
        A[2]=LSBDN::LEGGI_BYTE(2,N); A[3]=LSBDN::LEGGI_BYTE(3,N);
    }
    uint32_t UNISCI_UINT32_T(uint8_t B_0,uint8_t B_1,uint8_t B_2,uint8_t B_3){
        uint32_t N;
        LSBDN::SCRIVI_BYTE(0,N,B_0); LSBDN::SCRIVI_BYTE(1,N,B_1);
        LSBDN::SCRIVI_BYTE(2,N,B_2); LSBDN::SCRIVI_BYTE(3,N,B_3);
        return N;
    }
    uint8_t DIVIDI_IN_OTTO_UINT64_T(uint64_t N,uint8_t A[8]){
        A[0]=LSBDN::LEGGI_BYTE(0,N); A[1]=LSBDN::LEGGI_BYTE(1,N);
        A[2]=LSBDN::LEGGI_BYTE(2,N); A[3]=LSBDN::LEGGI_BYTE(3,N);
        A[4]=LSBDN::LEGGI_BYTE(4,N); A[5]=LSBDN::LEGGI_BYTE(5,N);
        A[6]=LSBDN::LEGGI_BYTE(6,N); A[7]=LSBDN::LEGGI_BYTE(7,N);
    }
    uint64_t UNISCI_UINT64_T(uint8_t B_0,uint8_t B_1,uint8_t B_2,uint8_t B_3,uint8_t B_4,uint8_t B_5,uint8_t B_6,uint8_t B_7){
        uint64_t N;
        LSBDN::SCRIVI_BYTE(0,N,B_0); LSBDN::SCRIVI_BYTE(1,N,B_1);
        LSBDN::SCRIVI_BYTE(2,N,B_2); LSBDN::SCRIVI_BYTE(3,N,B_3);
        LSBDN::SCRIVI_BYTE(4,N,B_4); LSBDN::SCRIVI_BYTE(5,N,B_5);
        LSBDN::SCRIVI_BYTE(6,N,B_6); LSBDN::SCRIVI_BYTE(7,N,B_7);
        return N;
    }
};
#endif
