#ifndef NumByteFraschetta_h
#define NumByteFraschetta_h
namespace NumByteF{
    template <typename N>
    uint8_t ReadByte(uint8_t NumBytes,N &Num){
     uint8_t B;
     if(NumBytes == 0){
      for(uint8_t p=0; p<=7; p++){bitWrite(B,p,bitRead(Num,p));}
     }
     else if(NumBytes == 1){
      for(uint8_t p=8,b=0; p<=15; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 2){
      for(uint8_t p=16,b=0; p<=23; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 3){
      for(uint8_t p=24,b=0; p<=31; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 4){
      for(uint8_t p=32,b=0; p<=39; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 5){
      for(uint8_t p=40,b=0; p<=47; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 6){
      for(uint8_t p=48,b=0; p<=55; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     else if(NumBytes == 7){
      for(uint8_t p=56,b=0; p<=63; b++,p++){bitWrite(B,b,bitRead(Num,p));}
     }
     return B;
    }
    template <typename N>
    void WriteByte(uint8_t NumBytes,N &Num,const uint8_t &B){
     if(NumBytes == 0){
      for(uint8_t p=0; p<=7; p++){bitWrite(Num,p,bitRead(B,p));}
     }
     else if(NumBytes == 1){
      for(uint8_t p=8,b=0; p<=15; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 2){
      for(uint8_t p=16,b=0; p<=23; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 3){
      for(uint8_t p=24,b=0; p<=31; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 4){
      for(uint8_t p=32,b=0; p<=39; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 5){
      for(uint8_t p=40,b=0; p<=47; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 6){
      for(uint8_t p=48,b=0; p<=55; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
     else if(NumBytes == 7){
      for(uint8_t p=56,b=0; p<=63; b++,p++){bitWrite(Num,p,bitRead(B,b));}
     }
    }
};
#endif
