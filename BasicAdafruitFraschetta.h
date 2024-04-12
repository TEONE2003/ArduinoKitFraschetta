//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef BasicAdafruitFraschetta_h
#define BasicAdafruitFraschetta_h
#include "WifiFraschetta.h"
//#define BasicAdafruitDebugF
class BasicAdafruitFraschetta::WifiClientF{
    protected:
    const char server[] = "io.adafruit.com";
    String link;
    BasicAdafruitFraschetta():WifiClientF(){link = "";}
    BasicAdafruitFraschetta(const BasicAdafruitFraschetta&);
    BasicAdafruitFraschetta& operator= (const BasicAdafruitFraschetta&);
    public:

   static BasicAdafruitFraschetta& GetInstance(){
    static BasicAdafruitFraschetta i;
    return i;
    }

    void begin(String Username,String APIKey){
     link = "/api/v2/" + Username + "/feeds/0/data?x-aio-key=" + APIKey + "&limit=1";
    }

    bool connect(){return connect(server,80);}

    String Download(){
     BasicAdafruitFraschetta::connect();
     printMethod("GET",link);
     printHost(server);
     printConnectionClose();
     printClose();
      #ifdef BasicAdafruitDebugF
      Serial.println("request sent");
      if(200OK())Serial.println("request successful");
      else{stop(); return "";}
     #else
      if(!200OK()){stop(); return "";}
     #endif
     if(StreamFilter("value")){
      read(); read(); read();
      String s= readStringUntil('"');
      stop(); return s;
     }
     #ifdef BasicAdafruitDebugF
      Serial.println("value not found");
     #endif
      return "";
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
};

#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif