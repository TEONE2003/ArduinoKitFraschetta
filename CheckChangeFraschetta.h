#ifndef CheckChangeFraschetta_h
#define CheckChangeFraschetta_h
template <class T> class CheckChangeF{
 private: T V,Vs;
 public:
  CheckChangeF(T &V){this->V=V; Vs=this->V;}
  bool Changed(){if(Vs!=V){Vs=V; return 1; return 0;}}
};
#endif
