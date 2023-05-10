#ifndef ExecuteOnceFraschetta_h
#define ExecuteOnceFraschetta_h
class ExecuteOnceF{
 private: bool S;
 public:
  ExecuteOnceF(){S=0;}
  bool NoExecuted(){if(!S){S=1; return 1;} return 0;}
  bool Executed(){return !NoExecuted();}
  void Reset(){S=0;}
};
#endif
