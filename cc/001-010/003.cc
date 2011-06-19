// Project Euler Problem 003
//
// Find the largest prime factor of a composite number.

#include "primes1.h"
#include <cstdio>
#include <math.h>

typedef long int longint;

int main(char argv[]) {
  longint product = 600851475143;
  Primes1<longint> primes;
  longint limit = sqrt(product);
  longint max = 0;
  while (true) {
    longint prime = primes.next();
    if (prime > limit) {
      break;
    }
    if (product % prime == 0) {
      max = prime;
    }
  }
  printf("%ld\n", max);
}
