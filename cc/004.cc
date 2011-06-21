// Project Euler Problem 004
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <cstdio>

int palindrome(int n) {
  int t = n;
  int sum = 0;
  while (t) {
    sum = sum * 10 + (t % 10);
    t = t / 10;
  }
  return (sum == n);
}

int main(char argv[]) {
  int max = 0;
  for (int i = 999; i > 99; i--) {
    if (999 * i <= max) {
      break;
    }
    for (int j = 999; j >= i; j--) {
      int product = i * j;
      if (product <= max) {
        break;
      }
      if (palindrome(product)) {
        max = product;
      }
    }
  }
  printf("%d\n", max);
}
