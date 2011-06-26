// Project Euler Problem 033
//
// Discover all the fractions with an unorthodox cancelling method.

#include <cstdio>
#include "mymath.h"

int main(int argc, const char* argv[]) {
  int N = 1;
  int D = 1;
  for (int n1=1; n1<10; n1++) {
    for (int n2=1; n2<10; n2++) {
      if (n1==n2) continue;
      int n = n1*10+n2;
      for (int d1=n1+1; d1<10; d1++) {
        for (int d2=1; d2<10; d2++) {
          int d = d1*10+d2;
          if ((n2==d1) && (d*n1==n*d2)) {
            N *= n1;
            D *= d2;
          }
        }
      }
    }
  }
  printf("%d\n", D / gcd(N,D));
}
