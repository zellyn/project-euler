#ifndef MYUTIL_H
#define MYUTIL_H

#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> get_quoted_csv(const char* filename);

std::vector<std::string> read_lines(const char* filename);

#endif  // MYUTIL_H
