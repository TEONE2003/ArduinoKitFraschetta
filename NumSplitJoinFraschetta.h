#ifndef NumSplitJoinFraschetta_h
#define NumSplitJoinFraschetta_h
#include <NumByteFraschetta.h>
namespace NumSplitJoinF{
    uint8_t SplitIntoTwoUint16T(uint16_t N, uint8_t A[2]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
    }
    uint16_t JoinUint16T(uint8_t b0,uint8_t b1){
        uint16_t N;
        NumByteF::WriteByte(0,N,b0); NumByteF::WriteByte(1,N,b1);
        return N;
    }
    uint8_t SplitIntoFourUint32T(uint32_t N, uint8_t A[4]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
        A[2]=NumByteF::ReadByte(2,N); A[3]=NumByteF::ReadByte(3,N);
    }
    uint32_t JoinUint32T(uint8_t b0,uint8_t b1,uint8_t b2,uint8_t b3){
        uint32_t N;
        NumByteF::WriteByte(0,N,b0); NumByteF::WriteByte(1,N,b1);
        NumByteF::WriteByte(2,N,b2); NumByteF::WriteByte(3,N,b3);
        return N;
    }
    uint8_t SplitIntoEightUint64T(uint64_t N,uint8_t A[8]){
        A[0]=NumByteF::ReadByte(0,N); A[1]=NumByteF::ReadByte(1,N);
        A[2]=NumByteF::ReadByte(2,N); A[3]=NumByteF::ReadByte(3,N);
        A[4]=NumByteF::ReadByte(4,N); A[5]=NumByteF::ReadByte(5,N);
        A[6]=NumByteF::ReadByte(6,N); A[7]=NumByteF::ReadByte(7,N);
    }
    uint64_t JoinUint64T(uint8_t b0,uint8_t b1,uint8_t b2,uint8_t b3,uint8_t b4,uint8_t b5,uint8_t b6,uint8_t b7){
        uint64_t N;
        NumByteF::WriteByte(0,N,b0); NumByteF::WriteByte(1,N,b1);
        NumByteF::WriteByte(2,N,b2); NumByteF::WriteByte(3,N,b3);
        NumByteF::WriteByte(4,N,b4); NumByteF::WriteByte(5,N,b5);
        NumByteF::WriteByte(6,N,b6); NumByteF::WriteByte(7,N,b7);
        return N;
    }
};
#endif
