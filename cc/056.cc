// Project Euler Problem 056
//
// Considering natural numbers of the form, a^b, where a, b < 100,
// what is the maximum digital sum?

#include <cstdio>
#include <vector>

#include "bigmath.h"

int main(int argc, const char* argv[]) {
  int max = 0;
  for (int a=1; a < 100; a++) {
    for (int b=1; b < 100; b++) {
      Bignum10 bigA(a);
      bigA.Pow(b);
      int sum = bigA.DigitSum();
      if (sum > max) max = sum;
    }
  }
  printf("%d\n", max);
}
