// Project Euler Problem 028
//
// What is the sum of both diagonals in a 1001 by 1001 spiral?

#include <cstdio>
#include "limits.h"

int main(char argv[]) {
  int sum = 1;
  int n = 1;
  for (int i=2; i < 1001; i += 2) {
    for (int j=0; j<4; j++) {
      n += i;
      sum += n;
    }
  }
  printf("%d\n", sum);
}
