#ifndef LedFraschetta_h
#define LedFraschetta_h
#include <OutputFraschetta.h>
class LED:public USCITA {
 public:
  LED(){}
  LED(uint8_t PIN):USCITA(PIN){}
  LED(uint8_t PIN,MEMORIZZA_STATO SALVA):USCITA(PIN,SALVA){}
};
#endif
