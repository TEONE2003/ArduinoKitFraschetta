#ifndef ExecuteOnceWithStaticVarFraschetta_h
#define ExecuteOnceWithStaticVarFraschetta_h
bool ExecuteOnceWithStaticVarF(){static bool S=0; if(!S){S=1; return S;} return 0;}
#endif
