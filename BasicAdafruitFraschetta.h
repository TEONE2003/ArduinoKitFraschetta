//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef BasicAdafruitFraschetta_h
#define BasicAdafruitFraschetta_h
#include "WifiFraschetta.h"
//#define BasicAdafruitDebugF
class BasicAdafruitFraschetta{
    protected:
    const char server[] = "io.adafruit.com";
    const char link[] = "/api/v2/matteofraschetta/feeds/0/data?x-aio-key=e74a5c10a0b44791822a671d8ea45a85&limit=1";
    public:
     bool connect(){return WFCF.connect(server,80);}

    String Download(){
     BasicAdafruitFraschetta::connect();
     WFCF.printMethod("GET",link);
     WFCF.printHost(server);
     WFCF.printConnectionClose();
     WFCF.printClose();
      #ifdef BasicAdafruitDebugF
      Serial.println("request sent");
      if(WFCF.200OK())Serial.println("request successful");
      else{WFCF.stop(); return "";}
     #else
      if(!WFCF.200OK()){WFCF.stop(); return "";}
     #endif
     if(WFCF.StreamFilter("value")){
      WFCF.read(); WFCF.read(); WFCF.read();
      String s= WFCF.readStringUntil('"');
      WFCF.stop(); return s;
     }
     #ifdef BasicAdafruitDebugF
      Serial.println("value not found");
     #endif
      return "";
    }

    bool Upload(String Value){
     String Json = "{\"value\":\""+Value+"\"}";
     BasicAdafruitFraschetta::connect();
     WFCF.printMethod("POST",link);
     WFCF.printHost(server);
     WFCF.println("content-type: application/json; charset=utf-8");
     WFCF.printConnectionClose();
     WFCF.printJson(Json.c_str());
     #ifdef BasicAdafruitDebugF
      if(WFCF.200OK()){Serial.println("request successful"); return 0;}
     #else
      return WFCF.200OK();
     #endif
    }
}

#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif