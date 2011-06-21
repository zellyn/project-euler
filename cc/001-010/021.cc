// Project Euler Problem 021
//
// Evaluate the sum of all amicable pairs under 10000.

#include <cstdio>
#include <vector>
#include "primes1.h"

using namespace std;

int sum_divisors(int i, Primes1<int>& primes) {
  vector<int> d = primes.divisors(i);
  int sum = 0;
  for (vector<int>::iterator it = d.begin(); it != d.end(); it++) {
    sum += *it;
  }
  return sum;
}

int main(char argv[]) {
  Primes1<int> primes;
  int sum = 0;
  for (int i=2; i < 10000; i++) {
    int sd = sum_divisors(i, primes);
    if ((sd > i) && (sum_divisors(sd, primes)==i)) {
      sum += i + sd;
    }
  }
  printf("%d\n", sum);
}
