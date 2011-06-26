// Project Euler Problem 032
//
// Find the sum of all numbers that can be written as pandigital
// products.

#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int digits(int a) {
  int result = 0;
  for (int i=a; i; i/=10) {
    if (!(i%10)) {
      return 0x3ff;
    }
    int bit = (1<<(i%10));
    if (bit & result) {
      return 0x3ff;
    } else {
      result |= bit;
    }
  }
  return result;
}


int main(int argc, const char* argv[]) {
  int sum = 0;
  set<int> s;
  for (int i=1; i<100; i++) {
    if (i/10 == i%10) continue;
    int di = digits(i);
    double l10i = log10(i);
    for (int j=i+1; log10(j)+l10i <= 5; j++) {
      int dj = digits(j);
      if (di&dj) continue;
      int dij = digits(i*j);
      if ((di|dj) & dij) continue;
      if ((di|dj|dij) == 0x3fe) {
        if (s.insert(i*j).second) {
          sum += i*j;
        };
      }
    }
  }
  printf("%d\n", sum);
}
