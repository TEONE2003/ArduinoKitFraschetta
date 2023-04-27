#ifndef ObjectsSyncFraschetta_h
#define ObjectsSyncFraschetta_h
class ObjectsSyncF{
private: void void (*SendAllStatus)(void); bool invalidCommand;
public:
 ObjectsSyncF(void (*SendAllStatus)(void)){this->SendAllStatus=SendAllStatus; invalidCommand=0;}
 void ObjectsSync(String ReceivedString){invalidCommand=0; if(ReceivedString=="SYNC"){SendAllStatus();}else{invalidCommand=1;}}
 bool InvalidCommand(){return invalidCommand;}
};
#endif
