// Project Euler Problem 007
//
// Find the 10001st prime.

#include <cstdio>
#include "primes1.h"

typedef long int longint;

int main(char argv[]) {
  Primes1<longint> primes;
  printf("%ld\n", primes.get(10000));
}
