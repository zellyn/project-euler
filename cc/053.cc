// Project Euler Problem 053
//
// How many values of C(n,r), for 1 ≤ n ≤ 100, exceed one-million?

#include <cstdio>
#include <vector>

#include "factored.h"

int main(int argc, const char* argv[]) {
  vector<Factored> factorials;
  Factored f(1);
  factorials.push_back(f);
  for (int i = 2; i<=100; ++i) {
    f = f * Factored(i);
    factorials.push_back(f);
  }

  // C(n,r) = n!/(n!*(n-r)!)

  int count = 0;

  for (int n = 1; n <= 100; ++n) {
    Factored num = factorials[n-1];
    if (!(num > 1000000)) {
      continue;
    }
    for (int r = 1; r < n; ++r) {
      if (num / factorials[r-1] / factorials[n-r-1] > 1000000) {
        count++;
      }
    }
  }
  printf("%d\n", count);
}
