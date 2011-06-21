// Project Euler Problem 019
//
// How many Sundays fell on the first of the month during the
// twentieth century?

#include <cstdio>

// Thanks, Tomohiko Sakamoto
int dow(int y, int m, int d) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main(char argv[]) {
  int count = 0;
  for (int y = 1901; y < 2001; y++) {
    for (int m = 1; m<=12; m++) {
      count += !(dow(y, m, 1));
    }
  }
  printf("%d\n", count);
}
