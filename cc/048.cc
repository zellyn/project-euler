// Project Euler Problem 048
//
// Find the last ten digits of 1^1 + 2^2 + ... + 1000^1000.

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(int argc, const char* argv[]) {
  Bignum10 sum(0);

  for (int i = 1; i <= 1000; i++) {
    Bignum10 add(1);
    for (int j=0; j<i; j++) {
      add *= i;
      add.Resize(10);
    }
    sum += add;
    sum.Resize(10);
  }
  sum.Print();
}
