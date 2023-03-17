#ifndef PhysicalEntranceFraschetta_h
#define PhysicalEntranceFraschetta_h
class PhysicalEntranceF{
protected: uint8_t PinOpeningLimitSwitch,PinClosingLimitSwitch;
public:
  PhysicalEntranceF(){}
  PhysicalEntranceF(uint8_t PinOpeningLimitSwitch,uint8_t PinClosingLimitSwitch){
   this->PinOpeningLimitSwitch=PinOpeningLimitSwitch;
   this->PinClosingLimitSwitch=PinClosingLimitSwitch;
  }
  bool Opened(){return digitalRead(PinOpeningLimitSwitch);}
  bool Closed(){return digitalRead(PinClosingLimitSwitch);}
};
#endif
