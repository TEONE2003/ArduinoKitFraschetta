#ifndef NumSplitJoinFraschetta_h
#define NumSplitJoinFraschetta_h
#include <NumByteFraschetta.h>
namespace NumSplitJoinF{
    uint8_t SplitIntoTwoUint16T(uint16_t N, uint8_t A[2]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
    }
    uint16_t JoinUint16T(uint8_t B0,uint8_t B1){
        uint16_t N;
        NumByteF::WriteByte(0,N,B0); NumByteF::WriteByte(1,N,B1);
        return N;
    }
    uint8_t SplitIntoFourUint32T(uint32_t N, uint8_t A[4]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
        A[2]=NumByteF::ReadByte(2,N); A[3]=NumByteF::ReadByte(3,N);
    }
    uint32_t JoinUint32T(uint8_t B0,uint8_t B1,uint8_t B2,uint8_t B3){
        uint32_t N;
        NumByteF::WriteByte(0,N,B0); NumByteF::WriteByte(1,N,B1);
        NumByteF::WriteByte(2,N,B2); NumByteF::WriteByte(3,N,B3);
        return N;
    }
    uint8_t SplitIntoEightUint64T(uint64_t N,uint8_t A[8]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
        A[2]=NumByteF::ReadByte(2,N); A[3]=NumByteF::ReadByte(3,N);
        A[4]=NumByteF::ReadByte(4,N); A[5]=NumByteF::ReadByte(5,N);
        A[6]=NumByteF::ReadByte(6,N); A[7]=NumByteF::ReadByte(7,N);
    }
    uint64_t JoinUint64T(uint8_t B0,uint8_t B1,uint8_t B2,uint8_t B3,uint8_t B4,uint8_t B5,uint8_t B6,uint8_t B7){
        uint64_t N;
        NumByteF::WriteByte(0,N,B0); NumByteF::WriteByte(1,N,B1);
        NumByteF::WriteByte(2,N,B2); NumByteF::WriteByte(3,N,B3);
        NumByteF::WriteByte(4,N,B4); NumByteF::WriteByte(5,N,B5);
        NumByteF::WriteByte(6,N,B6); NumByteF::WriteByte(7,N,B7);
        return N;
    }
};
#endif
