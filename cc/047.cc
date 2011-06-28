// Project Euler Problem 047
//
// Find the first four consecutive integers to have four distinct
// primes factors.

#include <cstdio>
#include <set>
#include "primes1.h"

using namespace std;

int main(int argc, const char* argv[]) {
  Primes1<int> primes;

  bool done = false;
  int i = 100;
  while (!done) {
    i++;
    if (primes.is_prime(i)) continue;
    vector<pair<int, int> > v3 = primes.prime_factors(i+3);
    if (v3.size() != 4) {
      i += 3;
      continue;
    }
    vector<pair<int, int> > v2 = primes.prime_factors(i+2);
    if (v2.size() != 4) {
      i += 2;
      continue;
    }
    vector<pair<int, int> > v1 = primes.prime_factors(i+1);
    if (v1.size() != 4) {
      i += 1;
      continue;
    }
    vector<pair<int, int> > v0 = primes.prime_factors(i);
    if (v0.size() != 4) continue;
    done = true;
  }
  printf("%d\n", i);
}
