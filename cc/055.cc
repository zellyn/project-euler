// Project Euler Problem 055
//
// How many Lychrel numbers are there below ten-thousand?

#include <algorithm>
#include <cstdio>
#include <vector>
#include "bigmath.h"

#define LIMIT 50

bool IsPalindrome(const vector<int>& v) {
  size_t l = v.size() / 2;
  vector<int>::const_iterator it;
  vector<int>::const_reverse_iterator rit;
  for (it=v.begin(), rit=v.rbegin(); (it != v.end()) && (rit != v.rend()) && l; ++it, ++rit, --l) {
    if (*it != *rit) return false;
  }
  return true;
}

bool IsLychrel(int n) {
  vector<int> v;
  v.push_back(1);
  times_digits_reversed(v, n);

  int l = LIMIT;
  do {
    vector<int> v2 = v;
    reverse(v2.begin(), v2.end());
    addto_digits_reversed(v, v2);
    if (IsPalindrome(v)) return false;
  } while (--l);
  return true;
}

int main(int argc, const char* argv[]) {
  int count = 0;
  for (int i=1; i<10000; ++i) {
    if (IsLychrel(i)) count++;
  }
  printf("%d\n", count);
}
