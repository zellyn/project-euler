// Project Euler Problem 020
//
// Find the sum of digits in 100!

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(int argc, const char* argv[]) {
  Bignum10 a(1);

  for (int i=2; i<=100; i++) {
    a *= i;
  }
  printf("%d\n", a.DigitSum());
}
