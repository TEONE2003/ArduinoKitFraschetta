#ifndef DefaultSerialFraschetta_h
#define DefaultSerialFraschetta_h
#include <BasicSerialFraschetta.h>
class DefaultSerialF:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial.end(); Serial.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial.available()>0;}
 String string()override{return Serial.readString();}
 uint8_t Byte()override{return Serial.read();}
 char Char()override{return Serial.read();}
public:
 DefaultSerialF(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial.println(t);}
};

#ifdef __AVR_ATmega2560__ || __AVR_ATmega1280__
class DefaultSerial1F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial1.end(); Serial1.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial1.available()>0;}
 String string()override{return Serial1.readString();}
 uint8_t Byte()override{return Serial1.read();}
 char Char()override{return Serial1.read();}
public:
 DefaultSerial1F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial1.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial1.println(t);}
};

class DefaultSerial2F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial2.end(); Serial2.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial2.available()>0;}
 String string()override{return Serial2.readString();}
 uint8_t Byte()override{return Serial2.read();}
 char Char()override{return Serial2.read();}
public:
 DefaultSerial2F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial2.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial2.println(t);}
};

class DefaultSerial3F:public BasicSerialF{
protected:
 void InitializeIfNotInitialized()override{if(!Initialized()){Serial3.end(); Serial3.begin(Baud); I=1;}}
 boolean DataPresent()override{return Serial3.available()>0;}
 String string()override{return Serial3.readString();}
 uint8_t Byte()override{return Serial3.read();}
 char Char()override{return Serial3.read();}
public:
 DefaultSerial3F(uint32_t Baud=9600):BasicSerialF(Baud){}
 template <typename T>
 void Send(T t){InitializeIfNotInitialized(); Serial3.print(t);}
 template <typename T>
 void SendLn(T t){InitializeIfNotInitialized(); Serial3.println(t);}
};
#endif
#endif
