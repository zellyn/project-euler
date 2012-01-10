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
    vector<int> vec;
    vec.push_back(1);
    times_digits_reversed(vec, a);
    for (int b=1; b < 100; b++) {
      vector<int> vec2 = vec;
      pow_digits_reversed(vec2, b);
      int sum = sum_digits(vec2);
      if (sum > max) max = sum;
    }
  }
  printf("%d\n", max);
}
