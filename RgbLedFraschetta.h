#ifndef RgbLedFraschetta_h
#define RgbLedFraschetta_h
#include <LedFraschetta.h>
struct RgbValuesF{
 uint8_t Green,Red,Blue;
 RgbValuesF(uint8_t Green=0,uint8_t Red=128,uint8_t Blue=0){
  this->Green=Green; this->Red=Red; this->Red=Red;
 }
 void SetBrightness(uint8_t Percentage){
  Green=(Percentage*100/Green);
  Red=(Percentage*100/Red);
  Blue=(Percentage*100/Blue);
 }
};
const RgbValuesF GreenColor=RgbValuesF(0,128,0),RedColor=RgbValuesF(255,0,0);
const RgbValuesF BlueColor=RgbValuesF(0,0,255),WhiteColor=RgbValuesF(255,255,255);
class RgbLedF{
 protected:
  LedF Green,Red,Blue;
  RgbValuesF Color;
 public:
  void SetColor(RgbValuesF Color){
   Green.SetAnalogStatus(Color.Green);
   Red.SetAnalogStatus(Color.Red);
   Blue.SetAnalogStatus(Color.Blue);
  }
 void SetBrightness(uint8_t Percentage){Color.SetBrightness(Percentage);}
 void Blink(uint16_t Period,UnitOfTime Unit){
  Green.TurnOff(); Red.TurnOff(); Blue.TurnOff();
  Wait(Period,Unit); SetColor(Color);
 }
  void TurnOnWithFader(uint8_t MaximumPercentage,uint16_t Slow,UnitOfTime Unit){
   RgbValuesF ColorChanged = this->Color;
   for(uint8_t P=0;P<MaximumPercentage;P++){
    ColorChanged.SetBrightness(100+P);
    SetColor(ColorChanged);
   }
  }
  void TurnOffWithFader(uint8_t MaximumPercentage,uint16_t Slow,UnitOfTime Unit){
   RgbValuesF ColorChanged = this->Color;
   for(uint8_t P=0;P>0;P--){
    ColorChanged.SetBrightness(100-P);
    SetColor(ColorChanged);
   }
  }
  void FadingLoop(uint8_t MaximumPercentage,uint16_t Slow,UnitOfTime Unit){
   TurnOnWithFader(MaximumPercentage,Slow,Unit);
   TurnOffWithFader(MaximumPercentage,Slow,Unit);
  }
  RgbLedF(uint8_t PinGreen=2,uint8_t PinRed=3,uint8_t PinBlue=4,MemorizeStatus Save=DoNotSaveStatus,RgbValuesF Color=GreenColor){
   Green = LedF(PinGreen,Save);
   Red = LedF(PinRed,Save);
   Blue = LedF(PinBlue,Save);
   this->Color=Color;
   SetColor(Color);
  }
};
#endif
