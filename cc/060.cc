// Project Euler Problem 060
//
// Find a set of five primes for which any two primes concatenate to
// produce another prime.

#include <cstdio>
#include <map>
#include <math.h>

#include "primes1.h"

bool Good(int p1, int p2, Primes1<int>& primes) {
  int d1 =  (int)log10(p1) + 1;
  int d2 =  (int)log10(p2) + 1;
  int c1 = p1 * (int)pow(10.0, d2) + p2;
  if (!primes.lazy_is_prime(c1)) return false;
  int c2 = p2 * (int)pow(10.0, d1) + p1;
  if (!primes.lazy_is_prime(c2)) return false;
  return true;
}

int CheckN(vector<int>& five, vector<int>& candidates, int maxIndex, int toFind, Primes1<int>& primes) {
  if (toFind==0) {
    return five[0] + five[1] + five[2] + five[3] + five[4];
  }
  for (int i=maxIndex; i>=toFind-1; i--) {
    int prime = candidates[i];
    bool good = true;
    for (unsigned int j=toFind; j<five.size(); j++) {
      if (!Good(prime, five[j], primes)) {
	good = false;
	break;
      }
    }
    if (!good) continue;
    five[toFind-1] = prime;
    int subCheck = CheckN(five, candidates, maxIndex-1, toFind-1, primes);
    if (subCheck) return subCheck;
  }
  return 0;
}

int Check(int prime, map<int, vector<int> >& friends, Primes1<int>& primes) {
  if (friends[prime].size() < 5) return 0;
  vector<int> five(5);
  five[4] = prime;
  return CheckN(five, friends[prime], friends[prime].size() - 1, 4, primes);
}

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  primes.is_prime(3000000);
  int prime = primes.next();  // 2 is useless
  int max_prime = 30000;
  int answer = 1000000;  // bigger than anything
  map<int, vector<int> > friends;
  while (prime < max_prime) {
    prime = primes.next();
    if (prime==5) continue;
    friends[prime] = vector<int>();
    int other = 2;
    for (int i=1; other < prime; i++) {
      other = primes.get(i);
      if (other==5) continue;
      if (other==prime) continue;
      if (Good(prime, other, primes)) {
	friends[other].push_back(prime);
	friends[prime].push_back(other);
      }
    }
    int sum = Check(prime, friends, primes);
    if (sum && (sum < answer)) {
      answer = sum;
      if (sum < max_prime) max_prime = sum;
    }
  }
  printf("%d\n", answer);
}
