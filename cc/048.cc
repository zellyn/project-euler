// Project Euler Problem 048
//
// Find the last ten digits of 1^1 + 2^2 + ... + 1000^1000.

#include <cstdio>
#include <vector>
#include "bigmath.h"

using namespace std;

int main(int argc, const char* argv[]) {
  vector<int> sum;
  sum.push_back(0);

  for (int i = 1; i <= 1000; i++) {
    vector<int> add;
    add.push_back(1);
    for (int j=0; j<i; j++) {
      times_digits_reversed(add, i);
      add.resize(10);
    }
    addto_digits_reversed(sum, add);
    sum.resize(10);
  }
  long answer = 0;
  for (int i=9; i>=0; i--) {
    answer = answer * 10 + sum[i];
  }
  printf("%ld\n", answer);
}
