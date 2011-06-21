// Project Euler Problem 010
//
// Calculate the sum of all the primes below two million.

#include <cstdio>
#include "primes1.h"

typedef long int longint;

int main(char argv[]) {
  Primes1<longint> primes;
  longint sum = 0;
  longint p;
  while ((p = primes.next()) < 2e6) {
    sum += p;
  }
  printf("%ld\n", sum);
}
