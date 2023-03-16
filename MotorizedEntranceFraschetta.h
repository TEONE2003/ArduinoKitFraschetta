#ifndef MotorizedEntranceFraschetta_h
#define MotorizedEntranceFraschetta_h
enum StatusOfMovement:uint8_t{Closing=0,Opening=1};
class MotorizedEntranceF{
 protected:
  uint16_t OpeningLimitSwitch,ClosingLimitSwitch,AddressMotionStatusPosition;
 public:
  virtual void Open()=0;
  virtual void Close()=0;
  virtual boolean Opened()=0;
  virtual boolean Closed()=0;
  void MemorizeStaus(StatusOfMovement Staus){
   EEPROM.update(AddressMotionStatusPosition,Staus);
  }
  void CheckStausMotion(){
   if(EEPROM.read(AddressMotionStatusPosition)){Open();}
   else{Close();}
  }
  MotorizedEntranceF(uint16_t OpeningLimitSwitch,uint16_t ClosingLimitSwitch,uint16_t AddressMotionStatusPosition){
   this->AddressMotionStatusPosition=AddressMotionStatusPosition;
   this->OpeningLimitSwitch = OpeningLimitSwitch;
   this->ClosingLimitSwitch = ClosingLimitSwitch;
  }
};
#endif
