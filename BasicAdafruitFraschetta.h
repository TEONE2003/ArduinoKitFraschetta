#ifndef BasicAdafruitFraschetta_h
#define BasicAdafruitFraschetta_h
#define TimeoutServer 10000
//#define BasicAdafruitDebugF
class BasicAdafruitFraschetta{
    protected:
    const char server[] = "io.adafruit.com";
    const String link = "/api/v2/matteofraschetta/feeds/0/data?x-aio-key=e74a5c10a0b44791822a671d8ea45a85&limit=1";
    virtual int connect(const char *host,uint16_t port)=0;
    virtual void stop()=0;
    virtual void print(const char c[])=0;
    virtual void println(const char c[])=0;
    virtual void println()=0;
    virtual int read()=0;
    virtual String readStringUntil(char terminator)=0;
    virtual bool StreamFilter(const char[] *StringArray)=0;
    virtual bool 200OK()=0;
    virtual void printMethod(String Method,String Link)=0;
    virtual void printHost(String &server)=0;
    virtual void printConnectionClose()=0;
    virtual void printClose()=0;
    virtual void printJson(String &Json)=0;
    public:
     bool connect(){
      stop();
      unsigned long ST=millis();
      while(!connect(server.c_str(),80)){
        if(millis()-ST >=TimeoutServer){
         #ifdef BasicAdafruitDebugF
         Serial.println("Timeout, the server is not responding");
         #endif
         return 0;
        }
      }
      #ifdef BasicAdafruitDebugF
      Serial.println("Connected to server");
      #endif
      return 1;
    }

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
     BasicAdafruitFraschetta::connect();
     printMethod("POST",link);
     printHost();
     println("content-type: application/json; charset=utf-8");
     printConnectionClose();
     printJson(Json);
     #ifdef BasicAdafruitDebugF
      if(200OK()){Serial.println("request successful"); return 0;}
     #else
      return 200OK();
     #endif
    }
}

#endif