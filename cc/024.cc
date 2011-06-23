// Project Euler Problem 024
//
// What is the millionth lexicographic permutation of the digits 0, 1,
// 2, 3, 4, 5, 6, 7, 8 and 9?

#include <cstdio>
#include <string>

using namespace std;

unsigned int fact(unsigned int n) {
  unsigned int prod = 1;
  for (unsigned int i=2; i<=n; i++) {
    prod *= i;
  }
  return prod;
}

string permutecount(string digits, unsigned int index) {
  size_t l = digits.length();
  if (l==1) {
    return digits;
  }
  unsigned int combos = fact(l-1);
  if (index >= combos * l) {
    printf("Index to large!\n");
    exit(1);
  }
  size_t i = index / combos;
  return digits[i] + permutecount(digits.substr(0, i) + digits.substr(i+1), index - i * combos);
}

int main(char argv[]) {
  string digits = "0123456789";
  printf("%s\n", permutecount(digits, 1e6-1).c_str());
}
