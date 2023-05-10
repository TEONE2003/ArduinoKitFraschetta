#ifndef CheckChangeFraschetta_h
#define CheckChangeFraschetta_h
template <class T> class CheckChangeF{
 private: T Vs;
 public:
  CheckChangeF(){}
  CheckChangeF(T Value){Vs=Value;}
  bool Changed(T Value){if(Vs!=Value){Vs=Value; return 1;} return 0;}
};
#endif
