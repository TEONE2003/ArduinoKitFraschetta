#ifndef TimeFraschetta_h
#define TimeFraschetta_h
#include "stdint.h"
enum UnitOfTime{Nanoseconds,Microseconds,Milliseconds,Seconds,Minutes,Hours,Days,Weeks,BusinessMonths,Years,BusinessYears};
struct TimeF{
protected:
 uint64_t Remainder;
 uint64_t Divisor;
public:
 UnitOfTime Unit;
 double Value;
 double Nanoseconds(){
  switch(Unit){
   case UnitOfTime::Nanoseconds: Remainder=0; return Value;
   case UnitOfTime::Microseconds: Remainder=0; return Value*1000;
   case UnitOfTime::Milliseconds: Remainder=0; return Value*1000000;
   case UnitOfTime::Secondi: Remainder=0; return Value*1000000000;
   case UnitOfTime::Minutes: Remainder=0; return Value*60000000000;
   case UnitOfTime::Hours: Remainder=0; return Value*3600000000000;
   case UnitOfTime::Days: Remainder=0; return Value*8640000000000;
   case UnitOfTime::Weeks: Remainder=0; return Value*60480000000000;
   case UnitOfTime::BusinessMonths: Remainder=0; return Value*259200000000000;
   case UnitOfTime::Years: Remainder=0; return Value*3153600000000000;
   case UnitOfTime::BusinessYears: Remainder=0; return Value*3110400000000000;
  }
 }
 double Microseconds(){
  switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=1000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Remainder=0; return Value;
  case UnitOfTime::Milliseconds: Remainder=0; return Value*1000;
  case UnitOfTime::Secondi: Remainder=0; return Value*1000000;
  case UnitOfTime::Minutes: Remainder=0; return Value*60000000;
  case UnitOfTime::Hours: Remainder=0; return Value*3600000000;
  case UnitOfTime::Days: Remainder=0; return Value*86400000000;
  case UnitOfTime::Weeks: Remainder=0; return Value*604800000000;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*2592000000000;
  case UnitOfTime::Years: Remainder=0; return Value*31536000000000;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*31104000000000;
 }
}
 double Milliseconds(){
  switch(Unit){
   case UnitOfTime::Nanoseconds: Divisor=1000000; Remainder=Value%Divisor; return Value/Divisor;
   case UnitOfTime::Microseconds: Divisor=1000; Remainder=Value%Divisor; return Value/Divisor;
   case UnitOfTime::Milliseconds: Remainder=0; return Value;
   case UnitOfTime::Secondi: Remainder=0; return Value*1000;
   case UnitOfTime::Minutes: Remainder=0; return Value*60000;
   case UnitOfTime::Hours: Remainder=0; return Value*3600000;
   case UnitOfTime::Days: Remainder=0; return Value*86400000;
   case UnitOfTime::Weeks: Remainder=0; return Value*604800000;
   case UnitOfTime::BusinessMonths: Remainder=0; return Value*2592000000;
   case UnitOfTime::Years: Remainder=0; return Value*31536000000;
   case UnitOfTime::BusinessYears:Remainder=0; return Value*31104000000;
  }
 }
double Secondi(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=1000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=1000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=1000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Remainder=0; return Value;
  case UnitOfTime::Minutes: Remainder=0; return Value*60;
  case UnitOfTime::Hours: Remainder=0; return Value*3600;
  case UnitOfTime::Days: Remainder=0; return Value*86400;
  case UnitOfTime::Weeks: Remainder=0; return Value*604800;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*2592000;
  case UnitOfTime::Years: Remainder=0; return Value*31536000;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*31104000;
 }
}
double Minutes(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=60000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=60000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=60000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=60; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Remainder=0; return Value;
  case UnitOfTime::Hours: Remainder=0; return Value*60;
  case UnitOfTime::Days: Remainder=0; return Value*1440;
  case UnitOfTime::Weeks: Remainder=0; return Value*10080;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*43200;
  case UnitOfTime::Years: Remainder=0; return Value*525600;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*518400;
 }
}
double Hours(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=3600000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=3600000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=3600000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=3600; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=60; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Remainder=0; return Value;
  case UnitOfTime::Days: Remainder=0; return Value*24;
  case UnitOfTime::Weeks: Remainder=0; return Value*168;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*720;
  case UnitOfTime::Years: Remainder=0; return Value*8760;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*8640;
 }
}
double Days(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=86400000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=86400000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=86400000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=86400; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=1440; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Divisor=24; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Days: Remainder=0; return Value;
  case UnitOfTime::Weeks: Remainder=0; return Value*7;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*30;
  case UnitOfTime::Years: Remainder=0; return Value*365;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*360;
 }
}
double Weeks(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=60480000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=604800000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=604800000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=604800; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=10080; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Divisor=168; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Days: Divisor=7; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Weeks: Remainder=0; return Value;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value*210;
  case UnitOfTime::Years: Remainder=0; return Value*2555;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*2520;
 }
}
double BusinessMonths(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=2592000000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=42336000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=2592000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=2592000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=43200; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Divisor=720; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Days: Divisor=30; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Weeks:Divisor=4; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::BusinessMonths: Remainder=0; return Value;
  case UnitOfTime::Years: Remainder=0; return Value*4380;
  case UnitOfTime::BusinessYears: Remainder=0; return Value*4320;
 }
}
double Years(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=3153600000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=3153600000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=31536000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=31536000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=525600; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Divisor=8760; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Days: Divisor=365; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Weeks: Divisor=48; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::BusinessMonths: Divisor=12; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Years: Remainder=0; return Value;
  case UnitOfTime::BusinessYears: Remainder=0; return Value;
 }
}
double BusinessYears(){
 switch(Unit){
  case UnitOfTime::Nanoseconds: Divisor=31104000000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Microseconds: Divisor=31104000000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Milliseconds: Divisor=31104000000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Secondi: Divisor=518400000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Minutes: Divisor=31104000; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Hours: Divisor=8640; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Days: Divisor=360; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Weeks: Divisor=48; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::BusinessMonths: Divisor=12; Remainder=Value%Divisor; return Value/Divisor;
  case UnitOfTime::Years: Remainder=0; return Value;
  case UnitOfTime::BusinessYears: Remainder=0; return Value;
 }
}
TimeF ConvertedTo(UnitOfTime Unit){
 double Val=0;
switch(Unit){
 case UnitOfTime::Nanoseconds: Val = Nanoseconds(); break;
 case UnitOfTime::Microseconds: Val = Microseconds(); break;
 case UnitOfTime::Milliseconds: Val = Milliseconds(); break;
 case UnitOfTime::Secondi: Val = Secondi(); break;
 case UnitOfTime::Minutes: Val = Minutes(); break;
 case UnitOfTime::Hours: Val = Hours(); break;
 case UnitOfTime::Days: Val = Days(); break;
 case UnitOfTime::Weeks: Val = Weeks(); break;
 case UnitOfTime::BusinessMonths: Val = BusinessMonths(); break;
 case UnitOfTime::Years: Val = Years(); break;
 case UnitOfTime::BusinessYears: Val = BusinessYears(); break;
}
 return TimeF(Val,Unit);
}
void ConvertTo(UnitOfTime Unit){this->Value=ConvertedTo(Unit).Value; this->Unit=Unit; }
 uint64_t Remainder(){uint64_t r=Remainder; Remainder=0; return r;}
 void operator=(const TimeF &t){Unit=t.Unit; Value=t.Value;}
 boolean operator==(const TimeF &b){if(Value == b.Value && Unit == b.Unit){return 1;} return 0;}
 TimeF operator+(const TimeF &b){b.ConvertTo(Unit); TimeF t(Value+b.Value,Unit); return t;}
 TimeF operator-(const TimeF &b){b.ConvertTo(Unit); TimeF t(Value-b.Value,Unit); return t;}
 TimeF operator*(const TimeF &b){b.ConvertTo(Unit); TimeF t(Value*b.Value,Unit); return t;}
 uint64_t operator/(const TimeF &b){b.ConvertTo(Unit); return Value/b.Value;}
 TimeF operator%(const TimeF &b){b.ConvertTo(Unit); TimeF t(Value%b.Value,Unit); return t;}
 boolean operator>(const TimeF &b){b.ConvertTo(Unit); if(Value > b.Value){return 1;} return 0;}
 boolean operator<(const TimeF &b){b.ConvertTo(Unit); if(Value < b.Value){return 1;} return 0;}
 boolean operator>=(const TimeF &b){b.ConvertTo(Unit); if(Value >= b.Value){return 1;} return 0;}
 boolean operator<=(const TimeF &b){b.ConvertTo(Unit); if(Value <= b.Value){return 1;} return 0;}
 TimeF(uint64_t Value=0,UnitOfTime Unit=Milliseconds){this->Unit=Unit; this->Value=Value; Remainder=0; Divisor=0;}
};
void Wait(uint64_t Value,UnitOfTime Unit){TimeF t(Value,Unit); delayMicroseconds(t.Microseconds());}
void Wait(TimeF t){delayMicroseconds(t.Microseconds());}
#endif
