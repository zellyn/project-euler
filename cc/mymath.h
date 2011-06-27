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

// Return a bitmask of the digits present in a.
// Repeated digits = turn them all on!
int digits(int a) {
  int result = 0;
  for (int i=a; i; i/=10) {
    int bit = (1<<(i%10));
    if (bit & result) {
      return 0x3ff;
    } else {
      result |= bit;
    }
  }
  return result;
}

// Return a bitmask of the digits present in a. Assume a is w digits
// wide.
// Repeated digits = return -1
int digits(int a, int w) {
  int result = 0;
  int i = a;
  while (w) {
    int bit = (1<<(i%10));
    if (bit & result) {
      return -1;
    } else {
      result |= bit;
    }
    i /= 10;
    w--;
  }
  return result;
}

#endif  // MYMATH_H
