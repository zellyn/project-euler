// Project Euler Problem 022
//
// What is the total of all the name scores in the file of first
// names?

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include "myutil.h"

using namespace std;

int score(string s) {
  int sum = 0;
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    sum += *i - 'A' + 1;
  }
  return sum;
}

int main(int argc, const char* argv[]) {
  vector<string> names = get_quoted_csv("../data/p022_names.txt");
  sort(names.begin(), names.end());

  int sum = 0;
  int index = 1;
  for (vector<string>::iterator it=names.begin(); it != names.end(); it++) {
    sum += index++ * score(*it);
  }
  printf("%d\n", sum);
}
