#ifndef BIGMATH_H
#define BIGMATH_H

#include <vector>

using namespace std;

class Bignum10 {
 public:
  Bignum10(int initial) {
    Init(initial);
  }
  Bignum10() {
    Init(0);
  }
  void Init(int initial) {
    v.clear();
    do {
      v.push_back(initial % 10);
      initial /= 10;
    } while (initial);
  }
  bool NonZero() {
    return ((v.size() != 1) || (v[0] != 0));
  }
  void Div10() {
    v.erase(v.begin());
    if (v.size()==0) {
      v.push_back(0);
    }
  }
  void Resize(size_t size) {
    v.resize(size);
  }
  void Print();
  void Pow(unsigned int rhs);
  int DigitSum();
  int size() {
    return v.size();
  }
  bool IsPalindrome();
  Bignum10 Reversed();

  Bignum10& operator+=(const unsigned int& rhs);
  Bignum10& operator*=(const unsigned int& rhs);
  Bignum10& operator+=(Bignum10 rhs);
  Bignum10& operator*=(Bignum10 rhs);
  int operator[](const size_t index) {
    return v[index];
  }
  bool operator==(const Bignum10& rhs);
  bool operator<(const Bignum10& rhs);
  bool operator<=(const Bignum10& rhs);
  bool operator>(const Bignum10& rhs);
  bool operator>=(const Bignum10& rhs);

 private:
  int cmp(const Bignum10& rhs);

 private:
  vector<int> v;
};

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
