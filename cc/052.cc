// Project Euler Problem 052
//
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x,
// and 6x, contain the same digits in some order.

#include <cstdio>

int digitscores(int input) {
  int scores = 0;

  while (input>0) {
    scores += 1L << (3 * (input % 10));
    input /= 10;
  }

  return scores;
}

bool win(const int num) {
  int score = digitscores(num);
  for (int i=2; i<=6; i++) {
    if (digitscores(i*num) != score) {
      return false;
    }
  }
  return true;
}

int main(int argc, const char* argv[]) {
  int i = 1;
  while (!win(i)) {
    i++;
  }
  printf("%d\n", i);
}
