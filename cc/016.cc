// Project Euler Problem 016
//
// What is the sum of the digits of the number 2^1000?

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(int argc, const char* argv[]) {
  // 2 ^ 1000
  // 4 ^ 500
  // 16 ^ 250
  // 256 ^ 125;
  Bignum10 a(1);

  for (int i=0; i<125; i++) {
    a *= 256;
  }
  printf("%d\n", a.DigitSum());
}
