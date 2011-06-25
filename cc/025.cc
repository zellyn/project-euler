// Project Euler Problem 025
//
// What is the first term in the Fibonacci sequence to contain 1000
// digits?

#include <cstdio>
#include <cmath>
#include "bigmath.h"

int main(int argc, const char* argv[]) {
  BigUnsigned target(1);
  for (int i=1000; i > 1; i--) {
    target *= 10;
  }
  BigUnsigned a(1);
  BigUnsigned b(1);
  BigUnsigned* smaller = &a;
  BigUnsigned* larger = &b;
  BigUnsigned* t;
  int i = 3;
  while (true) {
    *smaller += *larger;
    t = smaller;
    smaller = larger;
    larger = t;
    if (*larger >= target) {
      break;
    }
    i++;
  }
  printf("%d\n", i);
}
