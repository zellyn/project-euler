// Project Euler Problem 022
//
// What is the total of all the name scores in the file of first
// names?

#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> get_names(const char* filename) {
  string line;
  ifstream myfile(filename);
  if (myfile.is_open()) {
    getline(myfile, line);
  }
  vector<string> retval;
  size_t lastpos = 0;
  size_t openpos;
  while ((openpos = line.find_first_of('"', lastpos)) != string::npos) {
    lastpos = openpos+1;
    size_t closepos = line.find_first_of('"', lastpos);
    if (closepos != string::npos) {
      lastpos = closepos+1;
      retval.push_back(line.substr(openpos+1, closepos-openpos-1));
    }
  }
  return retval;
}

int score(string s) {
  int sum = 0;
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    sum += *i - 'A' + 1;
  }
  return sum;
}

int main(int argc, const char* argv[]) {
  vector<string> names = get_names("../data/p022_names.txt");
  sort(names.begin(), names.end());

  int sum = 0;
  int index = 1;
  for (vector<string>::iterator it=names.begin(); it != names.end(); it++) {
    sum += index++ * score(*it);
  }
  printf("%d\n", sum);
}
