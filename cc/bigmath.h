#ifndef BIGMATH_H
#define BIGMATH_H

#include <vector>

using namespace std;

void print_digits(vector<int>& digits);

void addto_digits_reversed(vector<int>& target, vector<int>& add);

// Multiply a bigint by an int, in-place.
// v holds the bigint, one digit per entry, with the least-significant
// digit first.
void times_digits_reversed(vector<int>& digits, int plier);

// Multiply a bigint by a bigint, in-place.
// digits holds the bigint, one digit per entry, with the
// least-significant digit first, and the result.
void times_digits_reversed(vector<int>& digits, vector<int> plier);

void pow_digits_reversed(vector<int>& digits, int power);

int sum_digits(vector<int>& digits);

class BigUnsigned {
 public:
  BigUnsigned() {
    v.push_back(0);
  };
  BigUnsigned(unsigned int x) {
    v.push_back(x);
  }

  void print();
  BigUnsigned& operator+=(const unsigned int& rhs);
  BigUnsigned& operator+=(BigUnsigned& rhs);
  BigUnsigned& operator*=(const unsigned int& rhs);
  unsigned int operator[](size_t index);
  bool operator==(const BigUnsigned& rhs);
  bool operator<(const BigUnsigned& rhs);
  bool operator<=(const BigUnsigned& rhs);
  bool operator>(const BigUnsigned& rhs);
  bool operator>=(const BigUnsigned& rhs);

 private:
  int cmp(const BigUnsigned& rhs);

 private:
  vector<unsigned int> v;
};

#endif  // BIGMATH_H
