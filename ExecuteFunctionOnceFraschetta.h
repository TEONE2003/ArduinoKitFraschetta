#ifndef ExecuteFunctionOnceFraschetta_h
#define ExecuteFunctionOnceFraschetta_h
class ExecuteFunctionOnceF{
 private: void (*FunctionToExecuteOnce)(void); bool S;
 public:
  ExecuteFunctionOnceF(void (*FunctionToExecuteOnce)(void)){S=0; this->FunctionToExecuteOnce=FunctionToExecuteOnce;}
  void RunOnce(){if(!S){S=1; FunctionToExecuteOnce();}}
  void Reset(){S=0;}
};
#endif
