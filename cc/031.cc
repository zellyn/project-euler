// Project Euler Problem 031
//
// Investigating combinations of English currency denominations.

#include <cstdio>

int DENOMS[] = { 200, 100, 50, 20, 10, 5, 2, 1 };

int combos(int amt, int index) {
  int denom = DENOMS[index];
  if (denom == 1) {
    return 1;
  }

  int sum = 0;
  for (int i=amt/denom*denom; i >= 0; i-=denom) {
    sum += combos(amt-i, index+1);
  }
  return sum;
}

int main(int argc, const char* argv[]) {
  printf("%d\n", combos(200, 0));
}
