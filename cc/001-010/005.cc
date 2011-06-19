// Project Euler Problem 005
//
// What is the smallest number divisible by each of the numbers 1 to 20?

#include <cstdio>
#include <vector>
#include <map>
#include "primes1.h"

typedef long int longint;
typedef std::pair<longint, int> factor_pair;

int main(char argv[]) {
  Primes1<longint> primes;
  std::map<longint, int> m;
  for (int i=1; i<=20; i++) {
    std::vector<factor_pair> v = primes.factor(i);
    for(std::vector<factor_pair>::iterator it = v.begin(); it != v.end(); ++it) {
      longint prime = it->first;
      int count = it->second;
      if (!m.count(prime) || (count > m[prime])) {
        m[prime] = count;
      }
    }
  }
  longint result = 1;
  std::map<longint, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    for (int j = 0; j < it->second; j++) {
      result *= it->first;
    }
  }
  printf("%ld\n", result);
}
