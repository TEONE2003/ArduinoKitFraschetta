//#define ARDUINO_UNOWIFIR4
#ifdef ARDUINO_UNOWIFIR4
#ifndef WifiFraschetta_h
#define WifiFraschetta_h
#define TimerAvailableF 5000
#define TimeoutServer 10000
//#define StreamFilterDebug
//#define WifiDebugF
#include "WiFiS3.h"

void WiFiBeginF(const char* ssid, const char *pass=nullptr){
 int status=0;
  while (status != WL_CONNECTED) {
   #ifdef WifiDebugF
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
   #endif
   if(pass==nullptr){status = WiFi.begin(ssid);}
   else{status = WiFi.begin(ssid,pass);}
  }
  #ifdef WifiDebugF
   Serial.print("Connected to: ");
   Serial.println(ssid);
  #endif
}

class WifiClientF: public WiFiClient{
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

 bool StreamFilter(const char *StringArray,String *S=nullptr){
  #ifdef WifiDebugF
    if(WifiClientF::available()){
      Serial.print("looking for ");
      Serial.print('"');
      Serial.print(StringArray);
      Serial.print('"');
      Serial.println(" ...");
    }
  #endif
  unsigned int length = strlen(StringArray)-1;
  #ifdef StreamFilterDebug
    Serial.println("length: "+ String(length+1));
  #endif
  unsigned int i=0;
  bool next=0;
  char c = 0;
    while(WifiClientF::available()){
      c = read();
      #ifdef StreamFilterDebug
      Serial.print(c);
      #endif
      if(c==StringArray[i]){
       i++;
       if(i==length){
        #ifdef StreamFilterDebug
         Serial.println();
         Serial.print('"');
         Serial.print(StringArray);
         Serial.print('"');
         Serial.println(" found");
        #endif
        return true;
        }
      }
      else if (i!=0){i=0;}
      if(S!=nullptr){*S+=c;}
    }
   #ifdef WifiDebugF
    Serial.println("string not found");
    #endif
   return false;
}

int connect(const char *host,uint16_t port){
      unsigned long ST=millis();
      while(!WiFiClient::connect(host,port)){
        if(millis()-ST >=TimeoutServer){
         #ifdef WifiDebugF
         Serial.println("Timeout, the server is not responding");
         #endif
         return 0;
        }
      }
      #ifdef WifiDebugF
      Serial.println("Connected to server");
      #endif
      return 1;
    }

bool OK(){
#ifdef WifiDebugF
  if(StreamFilter("200 OK")){Serial.println("request successful"); return 1;}
  else{Serial.println("request unsuccessful"); return 0;}
  #endif
  return StreamFilter("200 OK");
}

void printMethod(String Method,String &Link){println(Method + char(32)+ Link + " HTTP/1.1");}
void printHost(const char *server){print("Host: "); println(server);}
void printConnection(const char *Connection){print("Connection: "); println(Connection);}
void printAccept(const char *Accept){print("Accept: "); print(Accept);}
void printClose(){println();}
void printJson(const char *Json){
 print("content-length: ");
 println(String(strlen(Json)));
 println();
 println(Json);
}
};

#endif
#else
#error This library requires an Arduino board with WiFi support.
#endif