#ifndef FIB_H
#define FIB_H

template <class T>
class Fib {
 public:
   Fib() : a(0), b(1) { };
  T next() {
    T c = a + b;
    a = b;
    b = c;
    return c;
  }
 private:
  T a;
  T b;
};

#endif  // FIB_H
