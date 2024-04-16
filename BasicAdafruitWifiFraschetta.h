//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef BasicAdafruitWifiFraschetta_h
#define BasicAdafruitWifiFraschetta_h
#include "WifiFraschetta.h"
//#define BasicAdafruitDebugF
class BasicAdafruitWifiF::WifiClientF{
    private:
     BasicAdafruitWifiF(const BasicAdafruitWifiF&);
     BasicAdafruitWifiF& operator= (const BasicAdafruitWifiF&);
     BasicAdafruitWifiF():WifiClientF(){link = ""; ReceivedString=""; Readable=false; Update=1000; STU=0;}
    protected:
     const char server[] = "io.adafruit.com";
     String link,ReceivedString;
     bool Readable;
     unsigned long Update,STU;
    public:

    static BasicAdafruitWifiF& GetInstance(){
     static BasicAdafruitWifiF i;
     return i;
    }

    void AdafruitBegin(String Username,String APIKey, unsigned long Update=1000){
     link = "/api/v2/" + Username + "/feeds/0/data?x-aio-key=" + APIKey + "&limit=1";
     this->Update=Update;
    }

    bool connect(){return connect(server,80);}

    void Download(){
     BasicAdafruitWifiF::connect();
     printMethod("GET",link);
     printHost(server);
     printConnectionClose();
     printClose();
      #ifdef BasicAdafruitDebugF
      Serial.println("request sent");
      if(200OK())Serial.println("request successful");
      else{stop(); return;}
     #else
      if(!200OK()){stop(); return;}
     #endif
     if(StreamFilter("value")){
      read(); read(); read();
      String s= readStringUntil('"');
      stop(); ReceivedString = s; Readable=true; return;
     }
     #ifdef BasicAdafruitDebugF
      Serial.println("value not found");
     #endif
    }

    bool Upload(String Value){
     String Json = "{\"value\":\""+Value+"\"}";
     connect();
     printMethod("POST",link);
     printHost(server);
     println("content-type: application/json; charset=utf-8");
     printConnectionClose();
     printJson(Json.c_str());
     #ifdef BasicAdafruitDebugF
      if(200OK()){Serial.println("request successful"); return 0;}
     #else
      return 200OK();
     #endif
    }

   void ReceiveString(){
    if(millis() - STU == Update){
        STU = millis();
        Download();
    }
   }

    void Send(String s){Upload();}
};

#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif