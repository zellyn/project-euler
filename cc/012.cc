// Project Euler Problem 012
//
// What is the value of the first triangle number to have over five
// hundred divisors?

#include <cstdio>
#include "primes1.h"

long int tri(long int n) {
  return n * (n+1) / 2;
}

int main(int argc, const char* argv[]) {
  Primes1<long int> primes;
  long int i = 0;
  long int t = 0;
  while (true) {
    i++;
    t = tri(i);
    if (primes.num_divisors(t) > 500) {
      break;
    }
  }
  printf("%ld\n", t);
}
