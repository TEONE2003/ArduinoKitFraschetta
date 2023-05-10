#ifndef ExecuteOnceInLoopFraschetta_h
#define ExecuteOnceInLoopFraschetta_h
class ExecuteOnceInLoopF{
 private: void (*FunctionToExecuteOnce)(void); bool S;
 public:
  ExecuteOnceInLoopF(void (*FunctionToExecuteOnce)(void)){S=0; this->FunctionToExecuteOnce=FunctionToExecuteOnce;}
  void RunOnce(){if(!S){S=1; FunctionToExecuteOnce();}}
  void Reset(){S=0;}
};
#endif
