// Project Euler Problem 016
//
// What is the sum of the digits of the number 2^1000?

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(char argv[]) {
  // 2 ^ 1000
  // 4 ^ 500
  // 16 ^ 250
  // 256 ^ 125;
  vector<int> digits;
  digits.push_back(1);

  for (int i=0; i<125; i++) {
    times_digits_reversed(digits, 256);
  }
  printf("%d\n", sum_digits(digits));
}
