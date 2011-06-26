// Project Euler Problem 034
//
// Find the sum of all numbers which are equal to the sum of the
// factorial of their digits.

#include <cstdio>

// fact(9) * 7 = 2540160, so we need go no higher

int fact(int n) {
  if (n<2) return 1;
  return n * fact(n-1);
}

int check(int n) {
  int sum = 0;
  for (int i=n; i; i/=10) {
    sum += fact(i%10);
    if (sum >n) return 0;
  }
  if (sum < n) return 0;
  return n;
}

int main(int argc, const char* argv[]) {
  int sum = 0;
  for (int i=10; i<2540160; i++) {
    sum += check(i);
  }
  printf("%d\n", sum);
}
