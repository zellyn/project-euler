// Project Euler Problem 049
//
// Find arithmetic sequences, made of prime terms, whose four digits
// are permutations of each other.

#include <cstdio>
#include <map>
#include <vector>
#include "primes1.h"

using namespace std;

unsigned long digits(int i) {
  unsigned long p = 0;
  unsigned int d;
  while (i) {
    d = i % 10;
    p += 1 << (3 * d);
    i /= 10;
  }
  return p;
}

int main(int argc, const char* argv[]) {
  map<unsigned long, vector<int> > m;
  Primes1<int> primes;

  int p = 0;

  while ((p = primes.next()) < 1000) { };

  do {
    m[digits(p)].push_back(p);
    p = primes.next();
  } while (p < 10000);

  map<unsigned long, vector<int> >::iterator it;
  for (it = m.begin(); it != m.end(); ++it) {
    vector<int> v = it->second;
    size_t s = v.size();
    if (s > 2) {
      for (size_t i=0; i<s-2; i++) {
        for (size_t j=i+1; j<s-1; j++) {
          for (size_t k=j+1; k<s; k++) {
            if ((v[k]-v[j]) == (v[j]-v[i])) {
              if ((v[i] == 1487) && (v[j] == 4817)) continue;
              printf("%d%d%d\n", v[i], v[j], v[k]);
              exit(0);
            }
          }
        }
      }
    }
  }
}
