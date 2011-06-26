// Project Euler Problem 040
//
// Finding the nth digit of the fractional part of the irrational
// number.

#include <cstdio>
#include <cmath>

int nth_digit(int n, int starts[]) {
  int zn = n-1;
  int i = 0;
  while (zn >= starts[i+1]) {
    i++;
  }
  int count = zn - starts[i];
  int number = count / (i+1) + pow(10, i);
  int div = pow(10, i - (count % (i+1)));
  return (number / div) % 10;
}

int main(int argc, const char* argv[]) {
  int starts[7] = { 0 };
  int t1 = 1;
  for (int i=0; i<6; i++) {
    int count = 9 * t1;
    starts[i+1] = starts[i] + (i+1) * count;
    t1 *= 10;
  }

  int prod = 1;
  int d = 10;
  for (int i = 0; i<6; i++) {
    prod *= nth_digit(d, starts);
    d *= 10;
  }
  printf("%d\n", prod);
}
