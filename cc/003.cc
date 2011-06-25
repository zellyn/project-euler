// Project Euler Problem 003
//
// Find the largest prime factor of a composite number.

#include "primes1.h"
#include <cstdio>
#include <math.h>

int main(int argc, const char* argv[]) {
  long product = 600851475143;
  Primes1<long> primes;
  long limit = sqrt(product);
  long max = 0;
  while (true) {
    long prime = primes.next();
    if (prime > limit) {
      break;
    }
    if (product % prime == 0) {
      max = prime;
    }
  }
  printf("%ld\n", max);
}
