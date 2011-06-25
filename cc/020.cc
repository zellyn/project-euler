// Project Euler Problem 020
//
// Find the sum of digits in 100!

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(int argc, const char* argv[]) {
  vector<int> digits;
  digits.push_back(1);

  for (int i=2; i<=100; i++) {
    times_digits_reversed(digits, i);
  }
  printf("%d\n", sum_digits(digits));
}
