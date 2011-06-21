// Project Euler Problem 014
//
// Find the longest sequence using a starting number under one
// million.

#include <cstdio>
#include <map>

int len(long int n, std::map<long int, int>& m) {
  if (m.count(n)) {
    return m[n];
  }
  int count = 0;
  if (n&1) {
    // Going up immediately goes down
    count = 2 + len((3*n+1)>>1, m);
  } else {
    count = 1 + len(n>>1, m);
  }
  m[n] = count;
  return count;
}

int main(char argv[]) {
  int max = 0;
  int nmax = 0;
  std::map<long int, int> m;
  m[1] = 1;
  // Best guesses are 3, 7, 11, ...
  for (long int i = 3; i < 1e6; i+=4) {
    if (m.count(i)) continue;
    int l = len(i, m);
    if (l > max) {
      max = l;
      nmax = i;
    }
  }
  printf("%d\n", nmax);
}
