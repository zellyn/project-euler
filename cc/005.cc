// Project Euler Problem 005
//
// What is the smallest number divisible by each of the numbers 1 to 20?

#include <cstdio>
#include <vector>
#include <map>
#include "primes1.h"

typedef std::pair<long, int> factor_pair;

int main(char argv[]) {
  Primes1<long> primes;
  std::map<long, int> m;
  for (int i=1; i<=20; i++) {
    std::vector<factor_pair> v = primes.prime_factors(i);
    for(std::vector<factor_pair>::iterator it = v.begin(); it != v.end(); ++it) {
      long prime = it->first;
      int count = it->second;
      if (!m.count(prime) || (count > m[prime])) {
        m[prime] = count;
      }
    }
  }
  long result = 1;
  std::map<long, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    for (int j = 0; j < it->second; j++) {
      result *= it->first;
    }
  }
  printf("%ld\n", result);
}
