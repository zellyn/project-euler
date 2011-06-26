// Project Euler Problem 038
//
// What is the max 1 to 9 pandigital that can be formed by
// multiplying a fixed number by 1, 2, 3, ... ?

#include <cstdio>
#include <cmath>
#include "mymath.h"

int cat_ints(int a, int b) {
  int p = log10(b) + 1;
  return pow(10.0, p) * a + b;
}

int main(int argc, const char* argv[]) {
  int max = 0;
  for (int i=0; i < 10000; i++) {
    int sum = 0;
    int bits = 1;  // pretend 0 is already set
    for (int j=1; j<6; j++) {
      int dj = digits(i*j);
      if (bits&dj) break;
      bits |= dj;
      sum = cat_ints(sum, i*j);
      if (bits==0x3ff && sum > max) {
          max = sum;
      }
    }
  }
  printf("%d\n", max);
}
