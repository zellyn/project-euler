// Project Euler Problem 057
//
// Investigate the expansion of the continued fraction for the square
// root of two.

#include <cstdio>

#include "bigmath.h"

/*
1 + 1/2 = 3/2
1 + 1/(2 + 1/2) = 7/5
1 + 1/(2 + 1/(2 + 1/2)) = 17/12
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29

Not counting the leading ones, we have a simple pattern:

1/2
2/5
5/12
12/29
29/70
70/169
169/408
*/

int main(int argc, const char* argv[]) {
  int count = 0;
  int hits = 0;
  Bignum10 top(0);
  Bignum10 bottom(1);
  while (++count <= 1000) {
    Bignum10 temp = bottom;
    bottom *= 2;
    bottom += top;
    top = temp;
    temp += bottom;
    if (temp.size() > bottom.size()) {
      hits++;
    }
  }
  printf("%d\n", hits);
}
