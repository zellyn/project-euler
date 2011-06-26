// Project Euler Problem 041
//
// What is the largest n-digit pandigital prime that exists?

#include <cstdio>
#include "primes1.h"
#include "mymath.h"
#include <climits>

// 1+...+8 = 36, and 1+...+9 = 45, so all 8- and 9-digit pandigitals
// are divisible by 3.

int check(int n) {
  int d = digits(n);
  if (d&1) return false;  // 0 not allowed
  d >>= 1;
  while (d) {
    if (!(d&1)) return false;  // missing digits not allowed
    d >>= 1;
  }
  return true;
}

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int max = 0;
  int p;
  while ((p=primes.next()) < 1e7) {
    if (p > 2143 && check(p)) {  // 2143 given in problem
      max = p;
    }
  }
  printf("%d\n", max);
}
