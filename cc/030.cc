// Project Euler Problem 030
//
// Find the sum of all the numbers that can be written as the sum of
// fifth powers of their digits.
//
// 9 ** 5 * 6 = 354294, so we only have to check up to 354294.

#include <cstdio>
#include <cmath>

int sum_of_fifths(int i) {
  int sum = 0;
  while (i) {
    sum += pow(i%10, 5);
    i /= 10;
  }
  return sum;
}

int main(int argc, const char* argv[]) {
  int sum = 0;
  for (int i=512; i<354294; i++) {
    if (sum_of_fifths(i) == i) {
      sum+=i;
    }
  }
  printf("%d\n", sum);
}
