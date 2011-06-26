#ifndef MYMATH_H
#define MYMATH_H

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

template <class T>
T gcd(T a, T b) {
  if (a < b) return gcd(b, a);

  if (b==0) return a;

  return gcd(b, a % b);
}

#endif  // MYMATH_H
