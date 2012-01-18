#include <fstream>
#include <string>
#include <vector>

#include "myutil.h"

using namespace std;

/* Read lines from a file */
vector<string> read_lines(const char* filename) {
  vector<string> retval;
  string line;
  ifstream myfile;
  myfile.open(filename);
  while (!myfile.eof()) {
    getline(myfile, line);
    if (line.length()) {
      retval.push_back(string(line));
    }
  }
  myfile.close();
  return retval;
}

/* Read a file of "WORD1","WORD2","WORD3",...,"WORDN" */
vector<string> get_quoted_csv(const char* filename) {
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

/* Read a file of int1, int2, ..., intN when each is > 0 */
vector<int> get_csv_ints(const char* filename) {
  string line;
  ifstream myfile(filename);
  if (myfile.is_open()) {
    getline(myfile, line);
  }
  vector<int> retval;
  line.push_back(',');
  const char* chars = line.c_str();
  int val = 0;
  do {
    if (*chars >= '0' and *chars <= '9') {
      val = val * 10 + (*chars - '0');
    } else if (*chars == ',') {
      retval.push_back(val);
      val = 0;
    }
  } while (*(++chars));
  return retval;
}
