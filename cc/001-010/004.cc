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
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int product = i * j;
      if ((product > max) && palindrome(product)) {
        max = product;
      }
    }
  }
  printf("%d\n", max);
}
