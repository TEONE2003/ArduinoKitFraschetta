#ifndef ExecuteOnceWithStaticVarFraschetta_h
#define ExecuteOnceWithStaticVarFraschetta_h
class ExecuteOnceWithStaticVarF{
 public: 
 ExecuteOnceWithStaticVarF(){}
 bool RunOnce(){static bool S=0; if(!S){S=1; return S;} return 0;}
};
#endif
