#ifndef VirtualClockFraschetta_h
#define VirtualClockFraschetta_h
#include <TimeFraschetta.h>
#include <VirtualStopwatchFraschetta.h>
class OROLOGIO_VIRTUALE:CronometroVirtualeF{
protected:
 ORARIO O;
public:
 OROLOGIO_VIRTUALE(uint64_t ORE=0,uint64_t MINUTI=0,uint64_t SECONDI=0,uint64_t MILLISECONDI=0,uint64_t MICROSECONDI=0,uint64_t NANOSECONDI=0):CronometroVirtualeF(MICROSECONDI){
  O=ORARIO(NANOSECONDI,MICROSECONDI,MILLISECONDI,SECONDI,MINUTI,ORA);
 }
 ORARIO LEGGI_ORARIO(){O = ORARIO(tempoPassato()); return O;}
};
#endif
