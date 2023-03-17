#ifndef DefaultBluetoothFraschetta_h
#define DefaultBluetoothFraschetta_h
#include <DefaultSerialFraschetta.h>
#include <AtCommands.h>

class DefaultBluetoothF:public DefaultSerialF,public AtCommands{
public:
 DefaultBluetoothF(uint32_t Baud=9600):DefaultSerialF(Baud){}
 void ReceiveString()override{DefaultSerialF::ReceiveString();}
 String ReadString()override{return DefaultSerialF::ReadString();}
 void Send(String s)override{DefaultSerialF::Send(s);}
 template <typename T>
 void Send(T t){DefaultSerialF::Send(t);}
};

#ifdef __AVR_Atmega2560__ || __AVR_Atmega1280__
class Default1BluetoothF:public DefaultSerial1F,public AtCommands{
public:
 Default1BluetoothF(uint32_t Baud=9600):DefaultSerial1F(Baud){}
 void ReceiveString()override{DefaultSerial1F::ReceiveString();}
 String ReadString()override{return DefaultSerial1F::ReadString();}
 void Send(String s)override{DefaultSerial1F::Send(s);}
};

class Default2BluetoothF:public DefaultSerial2F,public AtCommands{
public:
 Default2BluetoothF(uint32_t Baud=9600):DefaultSerial2F(Baud){}
 void ReceiveString()override{DefaultSerial2F::ReceiveString();}
 String ReadString()override{return DefaultSerial2F::ReadString();}
 void Send(String s)override{DefaultSerial2F::Send(s);}
};

class Default3BluetoothF:public DefaultSerial3F,public AtCommands{
public:
 Default3BluetoothF(uint32_t Baud=9600):DefaultSerial3F(Baud){}
 void ReceiveString()override{DefaultSerial3F::ReceiveString();}
 String ReadString()override{return DefaultSerial3F::ReadString();}
 void Send(String s)override{DefaultSerial3F::Send(s);}
};
#endif
#endif
