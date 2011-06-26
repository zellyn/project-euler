// Project Euler Problem 036
//
// Find the sum of all numbers less than one million, which are
// palindromic in base 10 and base 2.

#include <cstdio>

bool palin(int n, int base) {
  if (!n%base) return false;
  int rev = 0;
  for (int i=n; i; i/=base) {
    rev = rev * base + i%base;
  }
  return rev == n;
}

int main(int argc, const char* argv[]) {
  int sum = 0;
  for (int i=1; i<1e6; i++) {
    if (palin(i, 10) && palin(i, 2)) {
      sum += i;
    }
  }
  printf("%d\n", sum);
}
