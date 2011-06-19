// Project Euler Problem 002
//
// By considering the terms in the Fibonacci sequence whose values do
// not exceed four million, find the sum of the even-valued terms.

#include "fib.h"
#include <cstdio>

int main(char argv[]) {
  Fib<int> fib;
  int total = 0;
  int f = fib.next();
  while (f < 4e6) {
    if (f < 100) {
      printf("  %d - %d\n", f, total);
    }
    if (! (f&1)) {
      total += f;
    }
    f = fib.next();
  }
  printf("%d\n", total);
}
