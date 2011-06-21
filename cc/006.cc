// Project Euler Problem 006
//
// What is the difference between the sum of the squares and the
// square of the sums?

#include <cstdio>

typedef long int longint;

int main(char argv[]) {
  longint sum_of_squares = 0;
  longint sum = 0;
  for (longint i=1; i<=100; i++) {
    sum += i;
    sum_of_squares += i*i;
  }
  longint diff = sum * sum - sum_of_squares;
  printf("%ld\n", diff);
}
