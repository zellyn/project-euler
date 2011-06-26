// Project Euler Problem 037
//
// Find the sum of all eleven primes that are both truncatable from
// left to right and right to left.

#include <cstdio>
#include "primes1.h"

bool check(int n, Primes1<int>& primes) {
  if (n<10) return false;
  int top10 = 1;
  for (int nn = n/10; nn; nn /= 10) {
    if (!primes.is_prime(nn)) return false;
    top10 *= 10;
  }

  int nn = n;
  while (true) {
    nn = nn - (nn/top10 * top10);
    if (!nn) return true;
    if (!primes.is_prime(nn)) return false;
    top10 /= 10;
  }
}

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int sum = 0;
  int count = 0;
  while (count < 11) {
    int p = primes.next();
    if (check(p, primes)) {
      sum += p;
      count++;
    }
  }
  check(3797, primes);
  printf("%d\n", sum);
}
