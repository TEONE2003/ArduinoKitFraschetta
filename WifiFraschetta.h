//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef WifiFraschetta_h
#define WifiFraschetta_h
#define TimerAvailableF 5000
#define BeginDelay 10000
//#define WifiDebugF
#include "WiFiS3.h"

void WiFiBeginF(const char* ssid, const char *passphrase){
 int status =0;
      while (status != WL_CONNECTED) {
       #ifdef WifiDebugF
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
       #endif
       status = WiFi.begin(ssid, pass);
       delay(BeginDelay);
      }
}

void WiFiBeginF(const char* ssid){
 int status =0;
      while (status != WL_CONNECTED) {
       #ifdef WifiDebugF
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
       #endif
       status = WiFi.begin(ssid);
       delay(BeginDelay);
      }
}

class WifiClientF::WiFiClient{
 private: unsigned long STimer;
 public:
 WifiClientF():WiFiClient(){STimer=0;}
 int available()override{
        STimer=millis();
        while(!WiFiClient::available()){
         if(millis()-STimer >= TimerAvailableF){
            #ifdef WifiDebugF
             Serial.println("Timeout, there are no data to read it");
            #endif
            return 0;
         }
        }
        return WiFiClient::available();
    }

 bool StreamFilter(const char[] *StringArray){
  #ifdef WifiDebugF
    if(WifiClientF::available()){Serial.println("Find value...");}
  #endif
  unsigned int size = sizeof(StringArray);
  unsigned int i=0;
  bool next=0;
    while(WifiClientF::available()){
      char c = read();
      if(c==StringArray[i]){
       i++;
       if(i==size) return true;
      }
      else if (i!=0){i=0;}
    }
  }
   #ifdef WifiDebugF
    Serial.println("string not found");
    #endif
   return false;
}

bool 200OK(){
#ifdef WifiDebugF
  if(StreamFilter("200 OK")){return 1;}
  else{Serial.println("request unsuccessful"); return 0;}
  #endif
  return StreamFilter("200 OK");
}

#endif
#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif