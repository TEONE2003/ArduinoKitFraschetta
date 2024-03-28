#ifndef BasicAdafruitFraschetta_h
#define BasicAdafruitFraschetta_h
#define TimeoutServer 10000
//#define BasicAdafruitDebugF
class BasicAdafruitFraschetta{
    protected:
    const char server[] = "io.adafruit.com";
    const char link[] = "/api/v2/matteofraschetta/feeds/0/data?x-aio-key=e74a5c10a0b44791822a671d8ea45a85&limit=1";
    virtual bool connect(String &host,uint16_t port)=0;
    virtual void stop()=0;
    virtual void print(const char c[])=0;
    virtual void println(const char c[])=0;
    virtual void println()=0;
    virtual int read()=0;
    virtual String readStringUntil(char terminator)=0;
    virtual bool StreamFilter(const char[] *StringArray)=0;
    virtual bool 200OK()=0;
    virtual void printMethod(String Method,String &Link)=0;
    virtual void printHost(const char[] *server)=0;
    virtual void printConnectionClose()=0;
    virtual void printClose()=0;
    virtual void printJson(const char[] *Json)=0;
    public:
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
     BasicAdafruitFraschetta::connect();
     printMethod("POST",link);
     printHost();
     println("content-type: application/json; charset=utf-8");
     printConnectionClose();
     printJson(Json.c_str());
     #ifdef BasicAdafruitDebugF
      if(200OK()){Serial.println("request successful"); return 0;}
     #else
      return 200OK();
     #endif
    }
}

#endif