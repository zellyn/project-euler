// Project Euler Problem 006
//
// What is the difference between the sum of the squares and the
// square of the sums?

#include <cstdio>

int main(char argv[]) {
  long sum_of_squares = 0;
  long sum = 0;
  for (long i=1; i<=100; i++) {
    sum += i;
    sum_of_squares += i*i;
  }
  long diff = sum * sum - sum_of_squares;
  printf("%ld\n", diff);
}
