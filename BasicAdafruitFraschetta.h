#ifndef BasicAdafruitFraschetta_h
#define BasicAdafruitFraschetta_h
#define TimeoutServer 10000
//#define BasicAdafruitDebugF
class BasicAdafruitFraschetta{
    protected:
    const char server[] = "io.adafruit.com";
    virtual int connect(const char *host,uint16_t port)=0;
    virtual void stop()=0;
    virtual void print(const char c[])=0;
    virtual void println(const char c[])=0;
    virtual void println()=0;
    virtual int read()=0;
    virtual String readStringUntil(char terminator)=0;
    virtual bool StreamFilter(const char[] *StringArray)=0;
    virtual bool 200OK()=0;
    public:
     bool connect(){
      stop();
      unsigned long ST=millis();
      while(!connect(server,80)){
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
     println("GET /api/v2/matteofraschetta/feeds/0/data?x-aio-key=e74a5c10a0b44791822a671d8ea45a85&limit=1 HTTP/1.1");
     print("Host: ");
     println(server);
     println("Connection: close");
     println();
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
     println("POST /api/v2/matteofraschetta/feeds/0/data?x-aio-key=e74a5c10a0b44791822a671d8ea45a85&limit=1 HTTP/1.1");
     print("Host: ");
     println(server);
     println("content-type: application/json; charset=utf-8");
     println("connection: close");
     print("content-length: ");
     println(String(sizeof(Json));
     println();
     println(Json);
     #ifdef BasicAdafruitDebugF
      if(200OK()){Serial.println("request successful"); return 0;}
     #else
      return 200OK();
     #endif
    }
}

#endif