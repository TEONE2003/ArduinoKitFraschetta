#ifndef CheckChangeWithReferenceFraschetta_h
#define CheckChangeWithReferenceFraschetta_h
template <class T> class CheckChangeWithReferenceF{
 private: T *V,Vs;
 public:
  CheckChangeWithReferenceF(){}
  CheckChangeWithReferenceF(T &Value){V=&Value; Vs=Value;}
  bool Changed(){if(Vs!=*V){Vs=*V; return 1;} return 0;}
};
#endif
