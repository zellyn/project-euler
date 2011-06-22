// Project Euler Problem 021
//
// Evaluate the sum of all amicable pairs under 10000.

#include <cstdio>
#include <vector>
#include <bitset>
#include "primes1.h"

using namespace std;

// All numbers above this can be written as sums of abundant numbers
const int LIMIT = 28123;

vector<int> abundants(Primes1<int>& primes) {
  vector<int> v;
  for (int i=1; i<=LIMIT; i++) {
    if (primes.sum_divisors(i) > i) {
      v.push_back(i);
    }
  }
  return v;
}

int main(char argv[]) {
  Primes1<int> primes;
  vector<int> ab = abundants(primes);
  bitset<LIMIT+1> bits;
  size_t l = ab.size();

  for (size_t i=0; i<l; i++) {
    for (size_t j=i; j<l; j++) {
      int sum = ab[j] + ab[i];
      if (sum <= LIMIT) {
        bits.set(sum, true);
      }
    }
  }

  int sum = 0;
  for (int i=1; i <= LIMIT; i++) {
    if (!bits[i]) {
      sum += i;
    }
  }
  printf("%d\n", sum);
}
