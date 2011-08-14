// Project Euler Problem 051
//
// Find the smallest prime which, by changing the same part of the
// number, can form eight different primes.

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include "primes1.h"

using namespace std;

int atoi_sub(const string& s, const int digit) {
  string::const_iterator i;
  int retval = 0;
  for (i=s.begin(); i != s.end(); ++i) {
    retval *= 10;
    if (*i == '*') {
      retval += digit;
    } else {
      retval += *i - '0';
    }
  }
  return retval;
}

bool matches(const string& pattern, Primes1<int>& primes) {
  int fails = 0;
  int digit = 9;
  do {
    if ((digit==0) && pattern[0] == '*') {
      fails++;
    } else if (!primes.is_prime(atoi_sub(pattern, digit))) {
      fails++;
    }
    if (fails>2) return false;
  } while (--digit >= 0);
  return (fails==2);
}

void choose(const string& pattern, const string& prefix, const char digit,
            size_t start, int k, int n, vector<string>& v) {
  if (k > n) return;
  if (k == 0) {
    v.push_back(prefix + pattern.substr(start));
    return;
  }
  if (start>=pattern.size()) return;
  if (pattern[start] == digit) {
    choose(pattern, prefix + '*', digit, start+1, k-1, n-1, v);
    choose(pattern, prefix + pattern[start], digit, start+1, k, n-1, v);
  } else {
    choose(pattern, prefix + pattern[start], digit, start+1, k, n, v);
  }
}

vector<string> make_patterns(const string& s) {
  int digits[10] = { 0 };
  vector<string> v;
  string::const_iterator i;
  // Note the s.end() - 1: we don't include the last digit, because at
  // least one of eight digit choices would leave the number divisible
  // by three.
  for (i=s.begin(); i != s.end() - 1; ++i) {
    digits[*i - '0']++;
  }

  for (int j=0; j<10; j++) {
    if (digits[j] >= 3) {
      choose(s, "", j + '0', 0, 3, digits[j], v);
      if (digits[j] >= 6) {
        choose(s, "", j + '0', 0, 6, digits[j], v);
      }
    }
  }

  return v;
}

bool win(const string& s, Primes1<int>& primes) {
  vector<string> patterns = make_patterns(s);
  vector<string>::iterator i;
  for (i = patterns.begin(); i != patterns.end(); ++i) {
    if (matches(*i, primes)) return true;
  }
  return false;
}

int main(int argc, const char* argv[]) {
  Primes1<int> primes;
  int prime = 0;
  stringstream ss;
  while ((prime = primes.next()) < 1000);

  do {
    ss.str("");
    ss << prime;
    if (win(ss.str(), primes)) break;
    prime = primes.next();
  } while (true);

  printf("%d\n", prime);
}
