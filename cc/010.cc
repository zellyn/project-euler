// Project Euler Problem 010
//
// Calculate the sum of all the primes below two million.

#include <cstdio>
#include "primes1.h"

int main(int argc, const char* argv[]) {
  Primes1<long> primes;
  long sum = 0;
  long p;
  while ((p = primes.next()) < 2e6) {
    sum += p;
  }
  printf("%ld\n", sum);
}
