#ifndef NumByteFraschetta_h
#define NumByteFraschetta_h
namespace LSBDN{//LEGGI SCRIVI BYTE DEI NUMERI
    template <typename N>
    uint8_t LEGGI_BYTE(uint8_t NUM_BYTE,N &NUM){
     uint8_t B;
     if(NUM_BYTE == 0){
      for(uint8_t p=0; p<=7; p++){bitWrite(B,p,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 1){
      for(uint8_t p=8,b=0; p<=15; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 2){
      for(uint8_t p=16,b=0; p<=23; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 3){
      for(uint8_t p=24,b=0; p<=31; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 4){
      for(uint8_t p=32,b=0; p<=39; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 5){
      for(uint8_t p=40,b=0; p<=47; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 6){
      for(uint8_t p=48,b=0; p<=55; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     else if(NUM_BYTE == 7){
      for(uint8_t p=56,b=0; p<=63; b++,p++){bitWrite(B,b,bitRead(NUM,p));}
     }
     return B;
    }
    template <typename N>
    void SCRIVI_BYTE(uint8_t NUM_BYTE,N &NUM,const uint8_t &B){
     if(NUM_BYTE == 0){
      for(uint8_t p=0; p<=7; p++){bitWrite(NUM,p,bitRead(B,p));}
     }
     else if(NUM_BYTE == 1){
      for(uint8_t p=8,b=0; p<=15; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 2){
      for(uint8_t p=16,b=0; p<=23; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 3){
      for(uint8_t p=24,b=0; p<=31; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 4){
      for(uint8_t p=32,b=0; p<=39; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 5){
      for(uint8_t p=40,b=0; p<=47; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 6){
      for(uint8_t p=48,b=0; p<=55; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
     else if(NUM_BYTE == 7){
      for(uint8_t p=56,b=0; p<=63; b++,p++){bitWrite(NUM,p,bitRead(B,b));}
     }
    }
};
#endif
