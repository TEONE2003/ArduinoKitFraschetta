#ifndef TimeFraschetta_h
#define TimeFraschetta_h
#include "stdint.h"

enum UnitaDiTempo{Nanosecondi,Microsecondi,Millisecondi,Secondi,Minuti,Ore,Giorni,Settimane,MesiCommerciali,Anni,AnniCommerciali};
struct TempoF{
protected:
 uint64_t Resto;
 uint64_t Divisore;
public:
 UnitaDiTempo Unita;
 double Valore;
 double Nanosecondi(){
  switch(Unita){
   case UnitaDiTempo::Nanosecondi: Resto=0; return Valore;
   case UnitaDiTempo::Microsecondi: Resto=0; return Valore*1000;
   case UnitaDiTempo::Millisecondi: Resto=0; return Valore*1000000;
   case UnitaDiTempo::Secondi: Resto=0; return Valore*1000000000;
   case UnitaDiTempo::Minuti: Resto=0; return Valore*60000000000;
   case UnitaDiTempo::Ore: Resto=0; return Valore*3600000000000;
   case UnitaDiTempo::Giorni: Resto=0; return Valore*8640000000000;
   case UnitaDiTempo::Settimane: Resto=0; return Valore*60480000000000;
   case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*259200000000000;
   case UnitaDiTempo::Anni: Resto=0; return Valore*3153600000000000;
   case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*3110400000000000;
  }
 }
 double Microsecondi(){
  switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=1000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Resto=0; return Valore;
  case UnitaDiTempo::Millisecondi: Resto=0; return Valore*1000;
  case UnitaDiTempo::Secondi: Resto=0; return Valore*1000000;
  case UnitaDiTempo::Minuti: Resto=0; return Valore*60000000;
  case UnitaDiTempo::Ore: Resto=0; return Valore*3600000000;
  case UnitaDiTempo::Giorni: Resto=0; return Valore*86400000000;
  case UnitaDiTempo::Settimane: Resto=0; return Valore*604800000000;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*2592000000000;
  case UnitaDiTempo::Anni: Resto=0; return Valore*31536000000000;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*31104000000000;
 }
}
 double Millisecondi(){
  switch(Unita){
   case UnitaDiTempo::Nanosecondi: Divisore=1000000; Resto=Valore%Divisore; return Valore/Divisore;
   case UnitaDiTempo::Microsecondi: Divisore=1000; Resto=Valore%Divisore; return Valore/Divisore;
   case UnitaDiTempo::Millisecondi: Resto=0; return Valore;
   case UnitaDiTempo::Secondi: Resto=0; return Valore*1000;
   case UnitaDiTempo::Minuti: Resto=0; return Valore*60000;
   case UnitaDiTempo::Ore: Resto=0; return Valore*3600000;
   case UnitaDiTempo::Giorni: Resto=0; return Valore*86400000;
   case UnitaDiTempo::Settimane: Resto=0; return Valore*604800000;
   case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*2592000000;
   case UnitaDiTempo::Anni: Resto=0; return Valore*31536000000;
   case UnitaDiTempo::AnniCommerciali:Resto=0; return Valore*31104000000;
  }
 }
double Secondi(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=1000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=1000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=1000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Resto=0; return Valore;
  case UnitaDiTempo::Minuti: Resto=0; return Valore*60;
  case UnitaDiTempo::Ore: Resto=0; return Valore*3600;
  case UnitaDiTempo::Giorni: Resto=0; return Valore*86400;
  case UnitaDiTempo::Settimane: Resto=0; return Valore*604800;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*2592000;
  case UnitaDiTempo::Anni: Resto=0; return Valore*31536000;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*31104000;
 }
}
double Minuti(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=60000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=60000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=60000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=60; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Resto=0; return Valore;
  case UnitaDiTempo::Ore: Resto=0; return Valore*60;
  case UnitaDiTempo::Giorni: Resto=0; return Valore*1440;
  case UnitaDiTempo::Settimane: Resto=0; return Valore*10080;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*43200;
  case UnitaDiTempo::Anni: Resto=0; return Valore*525600;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*518400;
 }
}
double Ore(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=3600000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=3600000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=3600000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=3600; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=60; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Resto=0; return Valore;
  case UnitaDiTempo::Giorni: Resto=0; return Valore*24;
  case UnitaDiTempo::Settimane: Resto=0; return Valore*168;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*720;
  case UnitaDiTempo::Anni: Resto=0; return Valore*8760;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*8640;
 }
}
double Giorni(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=86400000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=86400000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=86400000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=86400; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=1440; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Divisore=24; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Giorni: Resto=0; return Valore;
  case UnitaDiTempo::Settimane: Resto=0; return Valore*7;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*30;
  case UnitaDiTempo::Anni: Resto=0; return Valore*365;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*360;
 }
}
double Settimane(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=60480000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=604800000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=604800000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=604800; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=10080; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Divisore=168; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Giorni: Divisore=7; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Settimane: Resto=0; return Valore;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore*210;
  case UnitaDiTempo::Anni: Resto=0; return Valore*2555;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*2520;
 }
}
double MesiCommerciali(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=2592000000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=42336000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=2592000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=2592000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=43200; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Divisore=720; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Giorni: Divisore=30; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Settimane:Divisore=4; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::MesiCommerciali: Resto=0; return Valore;
  case UnitaDiTempo::Anni: Resto=0; return Valore*4380;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore*4320;
 }
}
double Anni(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=3153600000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=3153600000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=31536000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=31536000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=525600; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Divisore=8760; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Giorni: Divisore=365; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Settimane: Divisore=48; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::MesiCommerciali: Divisore=12; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Anni: Resto=0; return Valore;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore;
 }
}
double AnniCommerciali(){
 switch(Unita){
  case UnitaDiTempo::Nanosecondi: Divisore=31104000000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Microsecondi: Divisore=31104000000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Millisecondi: Divisore=31104000000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Secondi: Divisore=518400000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Minuti: Divisore=31104000; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Ore: Divisore=8640; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Giorni: Divisore=360; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Settimane: Divisore=48; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::MesiCommerciali: Divisore=12; Resto=Valore%Divisore; return Valore/Divisore;
  case UnitaDiTempo::Anni: Resto=0; return Valore;
  case UnitaDiTempo::AnniCommerciali: Resto=0; return Valore;
 }
}
TempoF convertito_in(UnitaDiTempo Unita){
 double Val=0;
switch(Unita){
 case UnitaDiTempo::Nanosecondi: Val = Nanosecondi(); break;
 case UnitaDiTempo::Microsecondi: Val = Microsecondi(); break;
 case UnitaDiTempo::Millisecondi: Val = Millisecondi(); break;
 case UnitaDiTempo::Secondi: Val = Secondi(); break;
 case UnitaDiTempo::Minuti: Val = Minuti(); break;
 case UnitaDiTempo::Ore: Val = Ore(); break;
 case UnitaDiTempo::Giorni: Val = Giorni(); break;
 case UnitaDiTempo::Settimane: Val = Settimane(); break;
 case UnitaDiTempo::MesiCommerciali: Val = MesiCommerciali(); break;
 case UnitaDiTempo::Anni: Val = Anni(); break;
 case UnitaDiTempo::AnniCommerciali: Val = AnniCommerciali(); break;
}
 return TempoF(Val,Unita);
}
void converti_in(UnitaDiTempo Unita){this->Valore=convertito_in(Unita).Valore; this->Unita=Unita; }
 uint64_t Resto(){uint64_t r=Resto; Resto=0; return r;}
 void operator=(const TempoF &t){Unita=t.Unita; Valore=t.Valore;}
 boolean operator==(const TempoF &b){if(Valore == b.Valore && Unita == b.Unita){return 1;} return 0;}
 TempoF operator+(const TempoF &b){b.converti_in(Unita); TempoF t(Valore+b.Valore,Unita); return t;}
 TempoF operator-(const TempoF &b){b.converti_in(Unita); TempoF t(Valore-b.Valore,Unita); return t;}
 TempoF operator*(const TempoF &b){b.converti_in(Unita); TempoF t(Valore*b.Valore,Unita); return t;}
 uint64_t operator/(const TempoF &b){b.converti_in(Unita); return Valore/b.Valore;}
 TempoF operator%(const TempoF &b){b.converti_in(Unita); TempoF t(Valore%b.Valore,Unita); return t;}
 boolean operator>(const TempoF &b){b.converti_in(Unita); if(Valore > b.Valore){return 1;} return 0;}
 boolean operator<(const TempoF &b){b.converti_in(Unita); if(Valore < b.Valore){return 1;} return 0;}
 boolean operator>=(const TempoF &b){b.converti_in(Unita); if(Valore >= b.Valore){return 1;} return 0;}
 boolean operator<=(const TempoF &b){b.converti_in(Unita); if(Valore <= b.Valore){return 1;} return 0;}
 TempoF(uint64_t Valore=0,UnitaDiTempo Unita=Millisecondi){this->Unita=Unita; this->Valore=Valore; Resto=0; Divisore=0;}
};

void Aspetta(uint64_t Valore,UnitaDiTempo Unita){TempoF t(Valore,Unita); delayMicroseconds(t.Microsecondi());}
void Aspetta(TempoF t){delayMicroseconds(t.Microsecondi());}

#endif
