// Project Euler Problem 050
//
// Which prime, below one-million, can be written as the sum of the
// most consecutive primes?

#include <cstdio>
#include "primes1.h"


int main(int argc, const char* argv[]) {
  int longest = 21;  // Given in problem
  longest = 5;
  Primes1<int> primes;
  vector<int> sums;
  sums.push_back(0);
  int i = 0;
  while ((i<longest) || (sums[i] - sums[i-longest+1] < 1e6)) {
    sums.push_back(sums[i] + primes.next());
    i++;
  }
  int sum = 0;
  for (int j=0; j<=i-longest; j++) {
    for (int k=j+longest; k<i; k++) {
      int s = sums[k] - sums[j];
      if (s>1e6) break;
      if (!primes.is_prime(s)) continue;
      if ((k-j) < longest) continue;
      sum = s;
      longest = k-j;
    }
  }
  printf("%d\n", sum);
}
