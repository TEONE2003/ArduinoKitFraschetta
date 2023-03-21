#ifndef LedFraschetta_h
#define LedFraschetta_h
#include "OutputFraschetta.h"
class LedF:public OutputF {
 public: LedF(uint8_t Pin=0,MemorizeStatus Save=DoNotSaveStatus):OutputF(Pin,Save){}
};
#endif
