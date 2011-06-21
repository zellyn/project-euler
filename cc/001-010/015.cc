// Project Euler Problem 015
//
// Starting in the top left corner in a 20 by 20 grid, how many routes
// are there to the bottom right corner?

#include <cstdio>

int main(char argv[]) {
  // 40! / 20! / 20!  - 20! drops out 20 and below from numerator
  // = 40*39*...*21 / 20!  - 20-10! half-drops out even-numbered 40-22.
  // = 2*39*2*37*2*35*...*2*21 / 10!

  long long int product = 1;
  for (long long int i=21; i<40; i+=2) {
    product *= 2*i;
  }
  for (long long int i=10; i>0; i--) {
    product /= i;
  }
  printf("%lld\n", product);
}
