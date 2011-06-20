// Project Euler Problem 014
//
// Find the longest sequence using a starting number under one
// million.

#include <cstdio>
#include <map>

int len(long int n, std::map<long int, int>& m) {
  if (n == 1) {
    return 1;
  }

  if (m.count(n)) {
    return m[n];
  }
  int count = 1;
  if (n&1) {
    count = count + len(3*n+1, m);
  } else {
    count = count + len(n/2, m);
  }
  m[n] = count;
  return count;
}

int main(char argv[]) {
  int max = 0;
  int nmax = 0;
  std::map<long int, int> m;
  for (long int i = 1; i < 1e6; i++) {
    int l = len(i, m);
    if (l > max) {
      max = l;
      nmax = i;
    }
  }
  printf("%d\n", nmax);
}
