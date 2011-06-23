#ifndef BIGMATH_H
#define BIGMATH_H

#include "limits.h"
#include <cassert>
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

class BigUnsigned {
 public:
  BigUnsigned() {
    v.push_back(0);
  };
  BigUnsigned(unsigned int x) {
    v.push_back(x);
  }

  void print() {
    printf("[");
    vector<unsigned int>::iterator it;
    bool first = true;
    for (it = v.begin(); it != v.end(); ++it) {
      if (first) {
        first = false;
      } else {
        printf(", ");
      }
      printf("%u", *it);
    }
    printf("]\n");
  }

  BigUnsigned& operator+=(const unsigned int& rhs) {
    unsigned long carry = rhs;
    vector<unsigned int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
      if (!carry) {
        break;
      }
      carry += *it;
      *it = carry & UINT_MAX;
      carry >>= sizeof(int) * CHAR_BIT;
    }
    if (carry) {
      assert(carry <= UINT_MAX);
      v.push_back(carry);
    }
    return *this;
  }

  BigUnsigned& operator+=(BigUnsigned& rhs) {
    // this->print();
    // rhs.print();
    // (const_cast<BigUnsigned>(rhs)).print();
    unsigned long carry = 0;
    vector<unsigned int>::iterator i, j;
    for (i=v.begin(), j=rhs.v.begin(); i!=v.end() && j!=rhs.v.end(); ++i,++j) {
      carry += *i;
      carry += *j;
      *i = carry & UINT_MAX;
      carry >>= sizeof(int) * CHAR_BIT;
    }

    while (i!=v.end()) {
      carry += *i;
      *i = carry & UINT_MAX;
      carry >>= sizeof(int) * CHAR_BIT;
      ++i;
    }

    while (j!=rhs.v.end()) {
      carry += *j;
      v.push_back(carry & UINT_MAX);
      carry >>= sizeof(int) * CHAR_BIT;
      ++j;
    }

    if (carry) {
      assert (carry <= UINT_MAX);
      v.push_back(carry);
    }

    return *this;
  }

  BigUnsigned& operator*=(const unsigned int& rhs) {
    unsigned long carry = 0;
    vector<unsigned int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
      carry += (unsigned long)*it * (unsigned long)rhs;
      *it = carry & UINT_MAX;
      carry >>= sizeof(int) * CHAR_BIT;
    }
    while (carry) {
      v.push_back(carry & UINT_MAX);
      carry >>= sizeof(int) * CHAR_BIT;
    }
    return *this;
  }

  unsigned int operator[](size_t index) {
    assert(index < v.size());
    return v[index];
  }

  bool operator==(const BigUnsigned& rhs) {
    return cmp(rhs) == 0;
  }

  bool operator<(const BigUnsigned& rhs) {
    return cmp(rhs) < 0;
  }

  bool operator<=(const BigUnsigned& rhs) {
    return cmp(rhs) <= 0;
  }

  bool operator>(const BigUnsigned& rhs) {
    return cmp(rhs) > 0;
  }

  bool operator>=(const BigUnsigned& rhs) {
    return cmp(rhs) >= 0;
  }

 private:
  int cmp(const BigUnsigned& rhs) {
    size_t s1 = v.size();
    size_t s2 = rhs.v.size();
    if (s1 > s2) {
      return 1;
    }
    if (s1 < s2) {
      return -1;
    }

    vector<unsigned int>::iterator i = v.end();
    vector<unsigned int>::const_iterator j = rhs.v.end();
    do {
      --i; --j;
      if (*i > *j) {
        return 1;
      } else if (*i < *j) {
        return -1;
      }
    } while (i != v.begin());
    return 0;
  }

 private:
  vector<unsigned int> v;
};

#endif  // BIGMATH_H
