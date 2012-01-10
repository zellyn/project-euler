#include "bigmath.h"

#include "limits.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

Bignum10 Bignum10::Reversed() {
  Bignum10 retval;
  retval.v = v;
  reverse(retval.v.begin(), retval.v.end());
  while ((retval.v.size() > 1) && !retval.v.back()) {
    retval.v.pop_back();
  }
  return retval;
}

bool Bignum10::IsPalindrome() {
  if (v.size() == 1) return true;
  size_t l = v.size() / 2;
  vector<int>::const_iterator it;
  vector<int>::const_reverse_iterator rit;
  for (it=v.begin(), rit=v.rbegin(); (it != v.end()) && (rit != v.rend()) && l; ++it, ++rit, --l) {
    if (*it != *rit) return false;
  }
  return true;
}

void Bignum10::Print() {
  for (vector<int>::reverse_iterator it=v.rbegin(); it != v.rend(); ++it) {
    cout << *it;
  }
  cout << endl;
}

Bignum10::Bignum10&
Bignum10::operator+=(Bignum10 rhs) {
  int carry = 0;
  vector<int>::iterator i, j;
  for (i=v.begin(), j=rhs.v.begin(); i!=v.end() && j!=rhs.v.end(); ++i,++j) {
    carry += *i;
    carry += *j;
    *i = carry % 10;
    carry /= 10;
  }

  while (i!=v.end()) {
    carry += *i;
    *i = carry % 10;
    carry /= 10;
    ++i;
  }

  while (j!=rhs.v.end()) {
    carry += *j;
    v.push_back(carry % 10);
    carry /= 10;
    ++j;
  }

  if (carry) {
    assert (carry <= 9);
    v.push_back(carry);
  }
  return *this;
}

Bignum10::Bignum10&
Bignum10::operator*=(const unsigned int& rhs) {
  // Multiply by zero is easy
  if (rhs==0) {
    v.clear();
    v.push_back(0);
    return *this;
  }
  // Multiply by ten is easy
  if (rhs==10) {
    v.insert(v.begin(), 0);
    return *this;
  }

  int carry = 0;
  for (size_t i=0; i<v.size(); i++) {
    int prod = v[i] * rhs + carry;
    v[i] = prod % 10;
    carry = prod / 10;
  }
  while (carry) {
    v.push_back(carry % 10);
    carry /= 10;
  }
  return *this;
}

Bignum10::Bignum10&
Bignum10::operator*=(Bignum10 rhs) {
  Bignum10 v_copy = *this;
  this->Init(0);
  int shift = 0;
  while (rhs.NonZero()) {
    // shift over
    for (int i=0; i<shift; i++) {
      v_copy *= 10;
    }
    shift = 0;
    Bignum10 v_again = v_copy;

    // Grab up to five digits of the multiplier
    int power = 1;
    int multiplier = 0;
    for (int i=0; i<5; i++) {
      if (!rhs.NonZero()) break;
      multiplier += power * rhs[0];
      rhs.Div10();
      power *= 10;
      shift++;
    }

    if (multiplier) {
      // Multiply
      v_again *= multiplier;

      // Add to result
      *this += v_again;
    }
  }
    return *this;
}

void Bignum10::Pow(unsigned int rhs) {
  Bignum10 copy = *this;
  this->Init(1);
  while (rhs) {
    if (rhs & 1) {
      *this *= copy;
    }
    rhs >>= 1;
    copy *= copy;
  }
}

int Bignum10::DigitSum() {
  int sum = 0;
  for (size_t i=0; i<v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

bool
Bignum10::operator==(const Bignum10& rhs) {
  return cmp(rhs) == 0;
}

bool
Bignum10::operator<(const Bignum10& rhs) {
  return cmp(rhs) < 0;
}

bool
Bignum10::operator<=(const Bignum10& rhs) {
  return cmp(rhs) <= 0;
}

bool
Bignum10::operator>(const Bignum10& rhs) {
  return cmp(rhs) > 0;
}

bool
Bignum10::operator>=(const Bignum10& rhs) {
  return cmp(rhs) >= 0;
}

int Bignum10::cmp(const Bignum10& rhs) {
  size_t s1 = v.size();
  size_t s2 = rhs.v.size();
  if (s1 > s2) {
    return 1;
  }
  if (s1 < s2) {
    return -1;
  }

  vector<int>::reverse_iterator i = v.rbegin();
  vector<int>::const_reverse_iterator j = rhs.v.rbegin();
  do {
    if (*i > *j) {
      return 1;
    } else if (*i < *j) {
      return -1;
    }
    ++i; ++j;
  } while (i != v.rend());
  return 0;
}

void BigUnsigned:: print() {
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

BigUnsigned::BigUnsigned&
BigUnsigned::operator+=(const unsigned int& rhs) {
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

BigUnsigned::BigUnsigned&
BigUnsigned::operator+=(BigUnsigned& rhs) {
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

BigUnsigned::BigUnsigned&
BigUnsigned::operator*=(const unsigned int& rhs) {
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

unsigned int
BigUnsigned::operator[](size_t index) {
  assert(index < v.size());
  return v[index];
}

bool
BigUnsigned::operator==(const BigUnsigned& rhs) {
  return cmp(rhs) == 0;
}

bool
BigUnsigned::operator<(const BigUnsigned& rhs) {
  return cmp(rhs) < 0;
}

bool
BigUnsigned::operator<=(const BigUnsigned& rhs) {
  return cmp(rhs) <= 0;
}

bool
BigUnsigned::operator>(const BigUnsigned& rhs) {
  return cmp(rhs) > 0;
}

bool
BigUnsigned::operator>=(const BigUnsigned& rhs) {
  return cmp(rhs) >= 0;
}

int BigUnsigned::cmp(const BigUnsigned& rhs) {
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
