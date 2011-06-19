// Project Euler Problem 009
//
// Find the only Pythagorean triplet, {a, b, c}, for which a + b + c =
// 1000.

#include <cstdio>

int main(char argv[]) {
  int answer = 0;
  for (int a = 1; a < 334; a++) {
    for (int b = a; b < 1000-2*a; b++) {
      int c = 1000-a-b;
      if (a*a + b*b == c*c) {
        answer = a*b*c;
      }
    }
  }
  printf("%d\n", answer);
}
