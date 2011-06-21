#include <vector>
using namespace std;

// Multiply a bigint by an int, in-place.
// v holds the bigint, one digit per entry, with the least-significant
// digit first.
void times_digits_reversed(vector<int>& digits, int plier) {
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

int sum_digits(vector<int>& digits) {
  int sum = 0;
  for (size_t i=0; i<digits.size(); i++) {
    sum += digits[i];
  }
  return sum;
}
