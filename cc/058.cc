// Project Euler Problem 058
//
// Investigate the number of primes that lie on the diagonals of the
// spiral grid.

#include <cstdio>
#include "primes1.h"

int main(int argc, const char* argv[]) {
  Primes1<long int> primes;
  int n = 1;
  int p = 0;
  int last = 1;
  int side = 0;
  while (!p || (p*10 > n)) {
    side += 2;
    for (int i=0; i<4; i++) {
      last += side;
      n++;
      if (primes.lazy_is_prime(last)) p++;
    }
  }
  printf("%d\n", side+1);
}
