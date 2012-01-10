// Project Euler Problem 055
//
// How many Lychrel numbers are there below ten-thousand?

#include <cstdio>
#include <vector>
#include "bigmath.h"

#define LIMIT 50

bool IsLychrel(int n) {
  Bignum10 v(n);

  int l = LIMIT;
  do {
    Bignum10 v2 = v.Reversed();
    v += v2;
    if (v.IsPalindrome()) return false;
  } while (--l);
  return true;
}

int main(int argc, const char* argv[]) {
  int count = 0;
  for (int i=1; i<10000; ++i) {
    if (IsLychrel(i)) count++;
  }
  printf("%d\n", count);
}
