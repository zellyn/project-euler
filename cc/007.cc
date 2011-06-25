// Project Euler Problem 007
//
// Find the 10001st prime.

#include <cstdio>
#include "primes1.h"

int main(int argc, const char* argv[]) {
  Primes1<long> primes;
  printf("%ld\n", primes.get(10000));
}
