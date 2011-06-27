#ifndef MYUTIL_H
#define MYUTIL_H

#include <fstream>
#include <string>
#include <vector>

/* Read a file of "WORD1","WORD2","WORD3",...,"WORDN" */
std::vector<std::string> get_quoted_csv(const char* filename) {
  std::string line;
  std::ifstream myfile(filename);
  if (myfile.is_open()) {
    std::getline(myfile, line);
  }
  std::vector<std::string> retval;
  size_t lastpos = 0;
  size_t openpos;
  while ((openpos = line.find_first_of('"', lastpos)) != std::string::npos) {
    lastpos = openpos+1;
    size_t closepos = line.find_first_of('"', lastpos);
    if (closepos != std::string::npos) {
      lastpos = closepos+1;
      retval.push_back(line.substr(openpos+1, closepos-openpos-1));
    }
  }
  return retval;
}

#endif  // MYUTIL_H
