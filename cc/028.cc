// Project Euler Problem 028
//
// What is the sum of both diagonals in a 1001 by 1001 spiral?

#include <cstdio>
#include "limits.h"

// 43 44 45 46 47 48 49
// 42 21 22 23 24 25 26
// 41 20  7  8  9 10 27
// 40 19  6  1  2 11 28
// 39 18  5  4  3 12 29
// 38 17 16 15 14 13 30
// 37 36 35 34 33 32 31
//
// 1: 1
// 3: 3, 5, 7, 9, (diff = 2)
// 5: 13, 17, 21, 25, (diff = 4)
// 7: 31, 37, 43, 49, (diff = 6)

int main(int argc, const char* argv[]) {
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
