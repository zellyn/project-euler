// Project Euler Problem 014
//
// Find the longest sequence using a starting number under one
// million.

#include <cstdio>

using namespace std;

int len(long int n) {
  if (n < 3) return n;
  int count = 0;
  if (n&1) {
    // Going up immediately goes down
    count = 2 + len((3*n+1)>>1);
  } else {
    count = 1 + len(n>>1);
  }
  return count;
}

int main(char argv[]) {
  int max = 0;
  int nmax = 0;
  // Best guesses are 3, 7, 11, ...
  for (long int i = 3; i < 1e6; i+=4) {
    int l = len(i);
    if (l > max) {
      max = l;
      nmax = i;
    }
  }
  printf("%d\n", nmax);
}
