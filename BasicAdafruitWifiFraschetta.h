//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef BasicAdafruitWifiFraschetta_h
#define BasicAdafruitWifiFraschetta_h
#include "WifiFraschetta.h"
//#define BasicAdafruitDebugF
class BasicAdafruitWifiF: public WifiClientF{
    private:
     const char server[16] = "io.adafruit.com";
     BasicAdafruitWifiF(const BasicAdafruitWifiF&);
     BasicAdafruitWifiF& operator= (const BasicAdafruitWifiF&);
     BasicAdafruitWifiF():WifiClientF(){link = ""; ReceivedString=""; Readable=false; Update=2000; STU=0;}
    protected:
     
     String link;
     unsigned long Update,STU;
    public:
    String ReceivedString;
    bool Readable;
    
    static BasicAdafruitWifiF* GetInstance(){
     static BasicAdafruitWifiF i;
     return &i;
    }

    void AdafruitBegin(String Username,String APIKey,String Feed,unsigned long Update=800){
     link = "/api/v2/" + Username + "/feeds/" + Feed + "/data?x-aio-key=" + APIKey + "&limit=1";
     this->Update=Update;
    }

    bool connect(){return WifiClientF::connect(server,80);}

    void Download(){
     #ifdef BasicAdafruitDebugF
      Serial.println("download value...");
     #endif
     BasicAdafruitWifiF::connect();
     printMethod("GET",link);
     printHost(server);
     printAccept("application/json");
     printConnection("Keep-Alive");
     printClose();
      #ifdef BasicAdafruitDebugF
      Serial.println("request sent");
      if(OK())Serial.println("request successful");
      else{stop(); return;}
     #else
      if(!OK()){stop(); return;}
     #endif
     if(StreamFilter("value")){
      read(); read(); read(); read();
      char f ='"';
      ReceivedString="";
      Readable=StreamFilter(&f,&ReceivedString);
      #ifdef BasicAdafruitDebugF
      Serial.print("value: "); Serial.print('"'); Serial.print(ReceivedString); Serial.println('"');
      #endif
      return;
     }
     #ifdef BasicAdafruitDebugF
      Serial.println("value not found");
     #endif
    }

    bool Upload(String Value){
    #ifdef BasicAdafruitDebugF
    Serial.print("upload: "); Serial.print('"'); Serial.print(Value); Serial.println('"');
    #endif
     String Json = "{\"value\":\""+Value+"\"}";
     connect();
     printMethod("POST",link);
     printHost(server);
     println("content-type: application/json; charset=utf-8");
     printConnection("Keep-Alive");
     printJson(Json.c_str());
     #ifdef BasicAdafruitDebugF
      if(OK()){Serial.println("request successful"); return 1;}
     #else
      return OK();
     #endif
    }

   void ReceiveString(){
    if(millis() - STU >= Update){
        STU = millis();
        #ifdef BasicAdafruitDebugF
         Serial.println("Updating...");
        #endif
        Download();
    }
   }

    void Send(String s){Upload(s);}
};

#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif