// Project Euler Problem 035
//
// How many circular primes are there below one million?

#include <cstdio>
#include <cmath>
#include "primes1.h"

bool circular(int p, Primes1<int>& primes) {
  if (p<10) return true;
  int len = log10(p);
  int shift = pow(10.0, len);
  for (int i=0; i<len; i++) {
    p = (p % 10) * shift + (p/10);
    if (!primes.is_prime(p)) return false;
  }
  return true;
}

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int count = 0;
  int p;
  while ((p=primes.next()) < 1e6) {
    if (circular(p, primes)) {
      count++;
    }
  }
  printf("%d\n", count);
}
