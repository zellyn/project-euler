// Project Euler Problem 016
//
// What is the sum of the digits of the number 2^1000?

#include <cstdio>
#include <vector>

using namespace std;

// Multiply a bigint by an int, in-place.
// v holds the bigint, one digit per entry, with the least-significant
// digit first.
void times(vector<int>& digits, int plier) {
  int carry = 0;
  for (size_t i=0; i<digits.size(); i++) {
    int prod = digits[i] * plier + carry;
    digits[i] = prod % 10;
    carry = prod / 10;
  }
  while (carry) {
    digits.push_back(carry % 10);
    carry /= 10;
  }
}

int main(char argv[]) {
  // 2 ^ 1000
  // 4 ^ 500
  // 16 ^ 250
  // 256 ^ 125;
  vector<int> digits;
  digits.push_back(1);

  for (int i=0; i<125; i++) {
    times(digits, 256);
  }
  int sum = 0;
  for (size_t i=0; i<digits.size(); i++) {
    sum += digits[i];
  }
  printf("%d\n", sum);
}
