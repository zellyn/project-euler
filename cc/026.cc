// Project Euler Problem 026
//
// Find the value of d < 1000 for which 1/d contains the longest
// recurring cycle.

#include <cstdio>

int repeat_length(int i) {
  int repeats[1000] = {0};
  int index = 0;
  int q = 1;
  while (true) {
    while (q <= i) {
      index++;
      q *= 10;
    }
    if ((q % i) == 0)
      return 0;
    q -= i * (q/i);
    if (repeats[q])
      return index - repeats[q];
    repeats[q] = index;
  }
}

int main(int argc, const char* argv[]) {
  int max = 0;
  int maxlen = 0;
  for (int i=2; i<1000; i++) {
    int len = repeat_length(i);
    if (len > maxlen) {
      maxlen = len;
      max = i;
    }
  }
  printf("%d\n", max);
}
