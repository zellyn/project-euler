// Project Euler Problem 021
//
// Evaluate the sum of all amicable pairs under 10000.

#include <cstdio>
#include <vector>
#include "primes1.h"

using namespace std;

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int sum = 0;
  for (int i=2; i < 10000; i++) {
    int sd = primes.sum_divisors(i);
    if ((sd > i) && (primes.sum_divisors(sd)==i)) {
      sum += i + sd;
    }
  }
  printf("%d\n", sum);
}
