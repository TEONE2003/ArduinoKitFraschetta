#ifndef ExecuteOnceInLoopFraschetta_h
#define ExecuteOnceInLoopFraschetta_h
class ExecuteOnceInLoopF{
 private: void (*FunctionToExecuteOnce)(void);
 public:
  ExecuteOnceInLoopF(void (*FunctionToExecuteOnce)(void)){this->FunctionToExecuteOnce=FunctionToExecuteOnce;}
  void RunOnce(){static bool S=0; if(!S){S=1; FunctionToExecuteOnce();}}
};
#endif
