// Project Euler Problem 027
//
// Find a quadratic formula that produces the maximum number of primes
// for consecutive values of n.

#include <cstdio>
#include "primes1.h"

int runlength(int a, int b, Primes1<int>& primes) {
  int n = 0;
  while (primes.is_prime(n*n + a*n + b)) n++;
  return n;
}

int main(char argv[]) {
  Primes1<int> primes;
  int max = 0;
  int prodmax = 0;
  for (int a = -999; a < 1000; a++) {
    for (int b = -999; b < 1000; b++) {
      int l = runlength(a, b, primes);
      if (l > max) {
        max = l;
        prodmax = a * b;
      }
    }
  }
  printf("%d\n", prodmax);
}
