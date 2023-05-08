#ifndef ExecuteOnceWithNonStaticVarFraschetta_h
#define ExecuteOnceWithNonStaticVarFraschetta_h
class ExecuteOnceWithNonStaticVarF{
 private: bool S;
 public:
  ExecuteOnceWithNonStaticVarF(){S=0;}
  bool NoExecuted(){if(!S){S=1; return 1;} return 0;}
  bool Executed(){return !NoExecuted();}
  void Reset(){S=0;}
};
#endif
