// Project Euler Problem 001
//
// Add all the natural numbers below one thousand that are multiples
// of 3 or 5.

#include <cstdio>

int main(char argv[]) {
  int total = 0;
  for (int i = 0; i < 1000; i++) {
    if ((i % 3) * (i % 5) == 0) {
      total += i;
    }
  }
  printf("Total: %d\n", total);
}
