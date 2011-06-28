// Project Euler Problem 046
//
// What is the smallest odd composite that cannot be written as the
// sum of a prime and twice a square?

#include <cstdio>
#include "primes1.h"

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int i = 33;
  bool done = false;
  while (!done) {
    i += 2;
    if (primes.is_prime(i)) continue;
    done = true;
    for (int s = 1; 2*s*s<i; s++) {
      if (primes.is_prime(i-2*s*s)) {
        done = false;
        break;
      }
    }
  }
  printf("%d\n", i);
}
