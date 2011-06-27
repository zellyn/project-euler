// Project Euler Problem 042
//
// How many triangle words does the list of common English words
// contain?

#include <cstdio>
#include <string>
#include <vector>
#include "myutil.h"

using namespace std;

bool check(string& word) {
  int sum = 0;
  for (string::iterator it=word.begin(); it != word.end(); ++it) {
    sum += *it - 'A' + 1;
  }
  int n = 1;
  while (true) {
    int tri = n * (n+1) / 2;
    if (tri==sum) return true;
    if (tri>sum) return false;
    n++;
  }
}

int main(int argc, const char* argv[]) {
  vector<string> words = get_quoted_csv("../data/p042_words.txt");
  int count = 0;
  for (vector<string>::iterator it=words.begin(); it != words.end(); ++it) {
    if (check(*it)) count++;
  }
  printf("%d\n", count);
}
